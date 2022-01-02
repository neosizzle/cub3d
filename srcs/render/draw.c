#include "cub3d.h"

//determines sides and initalizes values needed to call draw_texture_image();
static void	paint_texture_line(t_root *root, t_ray *ray, t_line *line, double wall_x)
{
	t_image	*img;
	int		tex_x;

	img = root->no_texture;
	if (ray->side == 1)
		img = root->ea_texture;
	else if (ray->side == 0)
		img = root->we_texture;
	else if (ray->side == 3)
		img = root->no_texture;
	else if (ray->side == 2)
		img = root->so_texture;
	tex_x = (int)(wall_x * (double)img->width);
	if ((ray->side == 0 || ray->side == 1) && ray->ray_dir_x > 0)
		tex_x = img->width - tex_x - 1;
	else if ((ray->side == 2 || ray->side == 3) && ray->ray_dir_y < 0)
		tex_x = img->width - tex_x - 1;
	line->y0 = ray->draw_start;
	line->y1 = ray->draw_end;
	line->tex_x = tex_x;
	draw_texture_image(root, ray, line, img);
}

//draw textures on screen as well as floor and ceil
void	draw_textures(t_root *root, t_ray *ray, t_player *player)
{
	t_line	*line;
	double	wall_x;

	line = malloc(sizeof (t_line));
	ft_bzero_inplace(line, sizeof(t_line));
	if (ray->side == 0 || ray->side == 1)
		wall_x = player->pos.y + ray->prep_wall_dist * ray->ray_dir_y;
	else
		wall_x = player->pos.x + ray->prep_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	line->x = ray->curr_x;
	if (root->game->map[ray->map_y][ray->map_x] == '1')
		paint_texture_line(root, ray, line, wall_x);
	// line->y0 = 0;
	// line->y1 = ray->draw_start;
	// paint_line(root, line, root->crgb);
	// line->y0 = WIN_HEIGHT;
	// line->y1 = ray->draw_end;
	// paint_line(root, line, root->frgb);
	free(line);
}