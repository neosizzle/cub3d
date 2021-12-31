#include "cub3d.h"

/*
** Function that sets carema and fov values for rendering elements on screen
** dir_x is not here cuz norme
*/
void	set_camera(t_root *root, double d_y, double p_x, double p_y)
{
	root->game->player->dir_vect.y = d_y;
	root->game->player->cam_plane_vect.x = p_x;
	root->game->player->cam_plane_vect.y = p_y;
}
