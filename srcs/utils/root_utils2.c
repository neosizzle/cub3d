#include "cub3d.h"

void	init_player(t_root *root)
{
	root->game->player = malloc(sizeof(t_player));
	if (!root->game->player)
		quit_root(root, "Error: malloc() failure in root->game->player\n", 1);
	root->game->player->dir_vect.x = 0;
	root->game->player->dir_vect.y = 0;
	root->game->player->cam_plane_vect.x = 0;
	root->game->player->cam_plane_vect.y = 0;
	root->game->player->pos.x = -123;
	root->game->player->pos.y = -123;
}