#include "cub3d.h"

/*
 Funtion to move backward
*/
void	move_backward(t_root *root)
{
	t_player	*player;
	t_game		*game;

	game = root->game;
	player = root->game->player;

	if (game->map
	[(int) (player->pos.y)]
	[(int) (player->pos.x - player->dir_vect.x * ceil(player->speed))] != '1')
		player->pos.x -= (player->speed * player->dir_vect.x);

	if (game->map
	[(int) ((player->pos.y - player->dir_vect.y * ceil(player->speed)))]
	[(int) (player->pos.x)] != '1')
		player->pos.y -= (player->speed * player->dir_vect.y);
}

/*
 Funtion to move left
*/
void	move_left(t_root *root)
{
	t_player	*player;
	t_game		*game;

	game = root->game;
	player = root->game->player;

	if (game->map
	[(int) (player->pos.y)]
	[(int) (player->pos.x - player->cam_plane_vect.x * ceil(player->speed))] != '1')
		player->pos.x -= (player->speed * player->cam_plane_vect.x);

	if (game->map
	[(int) ((player->pos.y - player->cam_plane_vect.y * ceil(player->speed)))]
	[(int) (player->pos.x)] != '1')
		player->pos.y -= (player->speed * player->cam_plane_vect.y);
}

/*
 Funtion to move right
*/
void	move_right(t_root *root)
{
	t_player	*player;
	t_game		*game;

	game = root->game;
	player = root->game->player;

	if (game->map
	[(int) (player->pos.y)]
	[(int) (player->pos.x + player->cam_plane_vect.x * ceil(player->speed))] != '1')
		player->pos.x += (player->speed * player->cam_plane_vect.x);

	if (game->map
	[(int) ((player->pos.y + player->cam_plane_vect.y * ceil(player->speed)))]
	[(int) (player->pos.x)] != '1')
		player->pos.y += (player->speed * player->cam_plane_vect.y);
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