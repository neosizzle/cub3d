/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jng <jng@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:49:54 by jng               #+#    #+#             */
/*   Updated: 2022/01/07 14:52:09 by jng              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Determines sides and initalizes values needed to call draw_texture_image();
**
** 1. Depending on ray->side, will set the img variable to the specific texture
** 2. Determine tex_x, the x coords of the texture.
**	(remember to handle the mirrors)
** 3. Set line draw start and draw end
** 4. Call draw_texture_image() which will then draw
**	the texture on the main image
**
** @param t_root *root - The root struct
** @param t_ray *ray - the ray struct
** @param t_line *line - The line struct to be drawn
** @param double wall_x - The exact location / x-coord the wall was hit by ray
*/
static void	paint_texture_line(
t_root *root,
t_ray *ray,
t_line *line,
double wall_x)
{
	t_image	*img;
	int		tex_x;

	img = root->no_texture;
	if (ray->side == EAST)
		img = root->ea_texture;
	else if (ray->side == WEST)
		img = root->we_texture;
	else if (ray->side == NORTH)
		img = root->no_texture;
	else if (ray->side == SOUTH)
		img = root->so_texture;
	tex_x = (int)(wall_x * (double)img->width);
	if ((ray->side == WEST || ray->side == EAST) && ray->ray_dir_x > 0)
		tex_x = img->width - tex_x - 1;
	else if ((ray->side == NORTH || ray->side == SOUTH) && ray->ray_dir_y < 0)
		tex_x = img->width - tex_x - 1;
	line->y0 = ray->draw_start;
	line->y1 = ray->draw_end;
	line->tex_x = tex_x;
	draw_texture_image(root, ray, line, img);
}

/*
** Draw textures on screen as well as floor and ceil
**
** 1. Initialize line struct which will be the struct neeed to be drawn
** 2. Calculate wall_x, which is the exact position of the wall hit on that wall
** 3. Set line x to the current x coord of the screen to draw
** 4. Call paint_texture_line() which will paint the walls
** 5. Reset line start and end y values
** 6 .Call paint_line() To paint ceiling
** 7. Repeat step 5 and 6 for floor
**
** @param t_root *root - the root struct
** @param t_ray *ray - the ray struct
** @param t_player *player - the player struct
*/
void	draw_textures(t_root *root, t_ray *ray, t_player *player)
{
	t_line	*line;
	double	wall_x;

	line = malloc(sizeof (t_line));
	ft_bzero_inplace(line, sizeof(t_line));
	if (ray->side == WEST || ray->side == EAST)
		wall_x = player->pos.y + ray->prep_wall_dist * ray->ray_dir_y;
	else
		wall_x = player->pos.x + ray->prep_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	line->x = ray->curr_x;
	if (root->game->map[ray->map_y][ray->map_x] == '1')
		paint_texture_line(root, ray, line, wall_x);
	line->y0 = 0;
	line->y1 = ray->draw_start;
	paint_line(root, line, root->crgb);
	line->y0 = WIN_HEIGHT;
	line->y1 = ray->draw_end;
	paint_line(root, line, root->frgb);
	free(line);
}
