/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jng <jng@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:52:46 by jng               #+#    #+#             */
/*   Updated: 2022/01/07 14:52:46 by jng              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//bug for bonus : segfault when player spams up down key to look around
// USEFUL LOGGING
// static int frame;

// ++frame;
// if (frame % 20 == 0)
// {
// 	printf("data accessed %d, idx %d\n", (int) texture->data[line->tex_y
// 		* texture->line_length + line->tex_x
//		* (texture->bits_per_pixel / 8)], line->tex_y
// 		* texture->line_length + line->tex_x * (texture->bits_per_pixel / 8));
// 	// printf("idx : %d, sizeof %ld\n", line->tex_y
// 	// * texture->line_length + line->tex_x
//		* (texture->bits_per_pixel / 8), sizeof(*texture->img_ptr));
// }
// printf("WIN_HEIGHT * root->game->player->cam_height %f\n"
//	, WIN_HEIGHT * root->game->player->cam_height);
// printf("accessing texture data at idx %d\n",line->tex_y
// 	* texture->line_length + line->tex_x * (texture->bits_per_pixel / 8));
// printf("accessing img data at idx %d\n", line->y
//	* root->mlx_img->line_length + line->x
// 	* root->mlx_img->bits_per_pixel / 8);
// printf("data accessed %d\n", (int) texture->data[line->tex_y
// 	* texture->line_length + line->tex_x * (texture->bits_per_pixel / 8)]);
// printf("ray->line_height %d\n",ray->line_height);
// printf("line->y %d\n",line->y);
// printf("line->tex_y %d\n",line->tex_y);
// printf("texture->line_length %d\n",texture->line_length);
//printf("line->x %d\n",line->x);
// printf("line->tex_x %d\n",line->tex_x);
// printf("texture->bits_per_pixel %d\n",
//	texture->bits_per_pixel);
/*
** Obtain scale and change data value according to texture on scale 
**
** 1. Calculate the scale from the screen to of the texture
** 2. Calculate the textures y coord to be printed with the scale
** 3. Set main image data to the textures image data
**	 based on tex_x and tex_y obtained
** 4. Reapeat for RGB
**
** @param t_root *root - the root struct
** @param t_ray *ray - the ray struct
** @param t_line *line - the line struct to be printed
** @param t_image *texture - the texture struct to be printed
*/
static void	texture_on_img(
t_root *root,
t_ray *ray,
t_line *line,
t_image *texture)
{
	int	scale;

	scale = line->y * texture->line_length
		- (WIN_HEIGHT * root->game->player->cam_height) * texture->line_length
		/ 2 + ray->line_height * texture->line_length / 2;
	line->tex_y = ((scale * texture->height) / ray->line_height)
		/ texture->line_length;
	root->mlx_img->data[line->y * root->mlx_img->line_length + line->x
		* root->mlx_img->bits_per_pixel / 8] = texture->data[line->tex_y
		* texture->line_length + line->tex_x * (texture->bits_per_pixel / 8)];
	root->mlx_img->data[line->y * root->mlx_img->line_length + line->x
		* (root->mlx_img->bits_per_pixel / 8) + 1] = texture->data[line->tex_y
		* texture->line_length + line->tex_x
		* (texture->bits_per_pixel / 8) + 1];
	root->mlx_img->data[line->y * root->mlx_img->line_length + line->x
		* (root->mlx_img->bits_per_pixel / 8) + 2] = texture->data[line->tex_y
		* texture->line_length + line->tex_x
		* (texture->bits_per_pixel / 8 ) + 2];
}

/*
** Function that prints a pixel on an image provided the rgb value
**
** 1. Calculate the r, g, and b values using bit manip
** 2. Set the iamge data according to the new values obtained
**
** @param int rgb - The rgb value
** @param int x - The x coordinate of the image you want to print
** @param int y - The y coordinate of the image you want to print
** @param y_iamge *img - The image struct
*/
static void	pixel_on_img(int rgb, int x, int y, t_image *img)
{
	int	r;
	int	g;
	int	b;

	r = (rgb >> 16) & 0xFF;
	g = (rgb >> 8) & 0xFF;
	b = rgb & 0xFF;
	img->data[y * img->line_length + x * img->bits_per_pixel / 8] = r;
	img->data[y * img->line_length + x * img->bits_per_pixel / 8 + 1] = g;
	img->data[y * img->line_length + x * img->bits_per_pixel / 8 + 2] = b;
}

/*
** Function that acts as a shelll function to draw all the textures in
** an image on 1 line (for walls)
**
** 1. Determine y-min and y-max
** 2. Call texture_on_img() for every row of that line
**
** @param t_root *root - The root struct
** @param t_ray *ray - The ray struct
** @param t_line *line - The line struct
** @param t_img *img - The image struct
*/
void	draw_texture_image(t_root *root, t_ray *ray, t_line *line, t_image *img)
{
	int	y_max;

	if (line->y0 < line->y1)
	{
		line->y = line->y0;
		y_max = line->y1;
	}
	else
	{
		line->y = line->y1;
		y_max = line->y0;
	}
	if (line->y >= 0)
	{
		line->y--;
		while (++line->y < y_max)
			texture_on_img(root, ray, line, img);
	}
}

/*
** Function that acts as a shell function to draw all the pixels in
** an image on 1 line (for floor and ceiling)
**
** 1. Determine y-min and y-max
** 2. Call texture_on_img() for every row of that line
**
** @param t_root *root - The root struct
** @param t_ray *ray - The ray struct
** @param t_line *line - The line struct
** @param t_img *img - The image struct
*/
void	paint_line(t_root *root, t_line *line, int rgb)
{
	int	y;
	int	y_max;

	if (line->y0 < line->y1)
	{
		y = line->y0;
		y_max = line->y1;
	}
	else
	{
		y = line->y1;
		y_max = line->y0;
	}
	if (y >= 0)
	{
		while (y < y_max)
		{
			pixel_on_img(rgb, line->x, y, root->mlx_img);
			y++;
		}
	}
}
