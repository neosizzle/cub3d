#include "cub3d.h"

/*
** Function that sets carema and fov values for rendering elements on screen
** dir_x is not here cuz norme
**
** @param t_root *root - The root struct
** @param double d_y - player direction vector y
** @param double p_x - player camera vector x
** @param double p_y - player camera vector y
*/
void	set_camera(t_root *root, double d_y, double p_x, double p_y)
{
	if (root->game->player_found)
		quit_root(root, "Error : multiple player init\n", 1);
	root->game->player->dir_vect.y = d_y;
	root->game->player->cam_plane_vect.x = p_x;
	root->game->player->cam_plane_vect.y = p_y;
	root->game->player_found++;
}

/*
** Function to turn left
**
** 1. Change the player direction vect according to this matrix formula in lodes
**	[ cos(a) -sin(a) ] *
**	[ sin(a)  cos(a) ]
**	(a is the angle of rotation / sensitivity)
** 2. Change the player camera vect as well
**
** @param t_root *root - The root struct
*/
void	turn_left(t_root *root)
{
	double	og_dirx;
	double	og_planex;
	double	sens;

	og_dirx = root->game->player->dir_vect.x;
	og_planex = root->game->player->cam_plane_vect.x;
	sens = root->game->player->sens;
	root->game->player->dir_vect.x =
			root->game->player->dir_vect.x * cos(-sens)
			- root->game->player->dir_vect.y * sin(-sens);
	root->game->player->dir_vect.y = og_dirx * sin(-sens)
			+ root->game->player->dir_vect.y * cos(-sens);
	root->game->player->cam_plane_vect.x =
			root->game->player->cam_plane_vect.x * cos(-sens)
			- root->game->player->cam_plane_vect.y * sin(-sens);
	root->game->player->cam_plane_vect.y = og_planex * sin(-sens)
			+ root->game->player->cam_plane_vect.y * cos(-sens);
}

/*
** Function to turn right
** 
** 1. Change the player direction vect according to this matrix formula in lodes
**	[ cos(a) -sin(a) ] *
**	[ sin(a)  cos(a) ]
**	(a is the angle of rotation / sensitivity)
** 2. Change the player camera vect as well
**
** @param t_root *root - The root struct
*/
void	turn_right(t_root *root)
{
	double	og_dirx;
	double	og_planex;
	double	sens;

	og_dirx = root->game->player->dir_vect.x;
	og_planex = root->game->player->cam_plane_vect.x;
	sens = root->game->player->sens;
	root->game->player->dir_vect.x =
			root->game->player->dir_vect.x * cos(sens)
			- root->game->player->dir_vect.y * sin(sens);
	root->game->player->dir_vect.y = og_dirx * sin(sens)
			+ root->game->player->dir_vect.y * cos(sens);
	root->game->player->cam_plane_vect.x =
			root->game->player->cam_plane_vect.x * cos(sens)
			- root->game->player->cam_plane_vect.y * sin(sens);
	root->game->player->cam_plane_vect.y = og_planex * sin(sens)
			+ root->game->player->cam_plane_vect.y * cos(sens);
}

/*
** Function to look up
**
** 1. Check if the camera height is at upper limit (2)
**  - If not, increment the camera height by sens
*/
void	look_up(t_root *root)
{
	double	*cam_height;
	double	sens;

	cam_height = &(root->game->player->cam_height);
	sens = root->game->player->sens;
	if (*cam_height < 2)
		*cam_height += (sens);
}

/*
** Function to look down
**
** 1. Check if the camera height is at lower limit (0)
**  - If not, decrement the camera height by sens
*/
void	look_down(t_root *root)
{
	double	*cam_height;
	double	sens;

	cam_height = &(root->game->player->cam_height);
	sens = root->game->player->sens;
	if (*cam_height > 0)
		*cam_height -= (sens);
}
