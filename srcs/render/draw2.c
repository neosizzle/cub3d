#include "cub3d.h"

//obtain scale and change data value according to texture on scale 
static void	texture_on_img(t_root *root, t_ray *ray, t_line *line, t_image *texture)
{
	int	scale;

	scale = line->y * texture->line_length  - (WIN_HEIGHT) * texture->line_length
			/ 2 + ray->line_height * texture->line_length / 2; // add cam height?
	line->tex_y = ((scale * texture->height) / ray->line_height)
		/ texture->line_length;
	// printf("accessing data at idx %d\n",line->tex_y
	// 	* texture->line_length + line->tex_x * (texture->bits_per_pixel / 8));
	// printf("data accessed %c\n", texture->data[line->tex_y
	// 	* texture->line_length + line->tex_x * (texture->bits_per_pixel / 8)]);
	// printf("ray->line_height %d\n",ray->line_height);
	// printf("line->y %d\n",line->y);
	// printf("line->tex_y %d\n",line->tex_y);
	// printf("texture->line_length %d\n",texture->line_length);
	//printf("line->x %d\n",line->x);
	// printf("line->tex_x %d\n",line->tex_x);
	// printf("texture->bits_per_pixel %d\n",texture->bits_per_pixel);
	root->mlx_img->data[line->y * root->mlx_img->line_length + line->x
		* root->mlx_img->bits_per_pixel / 8] = texture->data[line->tex_y
		* texture->line_length + line->tex_x * (texture->bits_per_pixel / 8)];
	root->mlx_img->data[line->y * root->mlx_img->line_length + line->x
		* root->mlx_img->bits_per_pixel / 8 + 1] = texture->data[line->tex_y
		* texture->line_length + line->tex_x * (texture->bits_per_pixel / 8 + 1)];
	root->mlx_img->data[line->y * root->mlx_img->line_length + line->x
		* root->mlx_img->bits_per_pixel / 8 + 2] = texture->data[line->tex_y
		* texture->line_length + line->tex_x * (texture->bits_per_pixel / 8 + 2)];
}

//determines y max and min and starts drawing texture on image
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