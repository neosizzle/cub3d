#include "cub3d.h"

/*
** Function that sets carema and fov values for rendering elements on screen
** dir_x is not here cuz norme
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
 Function to turn left 
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
 Function to turn right 
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
 Funtion to move forward
*/
void	move_forward(t_root *root)
{
	t_player	*player;
	t_game		*game;

	game = root->game;
	player = root->game->player;

	if (game->map
	[(int) (player->pos.y)]
	[(int) (player->pos.x + player->dir_vect.x * ceil(player->speed))] != '1')
		player->pos.x += (player->speed * player->dir_vect.x);

	if (game->map
	[(int) ((player->pos.y + player->dir_vect.y * ceil(player->speed)))]
	[(int) (player->pos.x)] != '1')
		player->pos.y += (player->speed * player->dir_vect.y);
}
