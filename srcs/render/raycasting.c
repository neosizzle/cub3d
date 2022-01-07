#include "cub3d.h"

/*
** Initialize default values for raycasting calculations
** 
** @param t_ray *ray - The ray struct
** @param t_player *player - The player struct
*/
static void	init_values(t_ray *ray, t_player *player)
{
	ray->cam_x = (2 * ray->curr_x) / (double) WIN_WIDTH - 1;
	ray->ray_dir_x = player->dir_vect.x + player->cam_plane_vect.x * ray->cam_x;
	ray->ray_dir_y = player->dir_vect.y + player->cam_plane_vect.y * ray->cam_x;
	ray->map_x = (int) player->pos.x;
	ray->map_y = (int) player->pos.y;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
}

/*
** Determine step direction as well as calculate sidestepdist
**
** @param t_ray *ray - The ray struct
** @param t_player *player - The player struct
*/
static void	determine_step(t_ray *ray, t_player *player)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->pos.x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player->pos.x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos.y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player->pos.y) * ray->delta_dist_y;
	}
}

/*
** This function determines the next wall face as well as the side
**
** 1. If the distance to the next x is closer to then next y, move in x direction
**	-move the ray according to step.
**	- if step is -1, wall the ray hits will be facing east
**	- else, wall the ray hits will be facing west
**
** 2. If the distance to the next y is closer to then next x, move in y direction
**	-move the ray according to step.
**	- if step is -1, wall the ray hits will be facing south
**	- else, wall the ray hits will be facing north
**
** @param t_ray *ray - The ray struct
*/
static void	get_next_wallface(t_ray *ray)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_dist_x;
		ray->map_x += ray->step_x;
		if (ray->step_x == -1)
			ray->side = EAST;
		else
			ray->side = WEST;
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		ray->map_y += ray->step_y;
		if (ray->step_y == -1)
			ray->side = SOUTH;
		else
			ray->side = NORTH;		
	}
}

/*
** Performs the "Digital Differential Analysis" algo
**
** 1. While our ray has not hit any surface
**	- determine the next intercept wall face
**	- check the new wall face if it hits a box or not
**
** @param t_root *root - the root struct
** @param t_ray *ray - The ray struct
*/
static void	perform_dda(t_root *root, t_ray *ray)
{
	while (!ray->hit)
	{
		get_next_wallface(ray);
		if (root->game->map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
	
}

/*
** Main raycasting function
** acts as a shell fucntion to call other subfunctions
**
** 1. Initializes ray object with player
** 2. Determine the step size of the ray
** 3. Perform DDA of raycasting until it hits a wall
** 4. Calculate the distance and obtain the height of wall
** 5. Draw the textures on the image
**
** @param t_root *root - The root struct
** @param t_ray *ray - The ray struct
*/
void	raycasting(t_root *root, t_ray *ray)
{
	t_player	*player;

	player = root->game->player;
	init_values(ray, player);
	determine_step(ray, player);
	perform_dda(root, ray);
	prep_height(ray, player);
	draw_textures(root, ray, player);
	ray->curr_x++;
}