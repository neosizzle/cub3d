#include "cub3d.h"

/*
** Funtion to move backward
**
** 1. Check the map if the direction that we are about to move into is a wall.
**	Taking speed into account.
**	- If not, move player according to player speed
** 2. Do the same for the y vector direction
**
** @param t_root *root - The root struct
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
** Funtion to move left
**
** 1. Check the map if the direction that we are about to move into is a wall.
**	Taking speed into account.
**	- If not, move player according to player speed
** 2. Do the same for the y vector direction
**
** @param t_root *root - The root struct
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
** Funtion to move right
**
** 1. Check the map if the direction that we are about to move into is a wall.
**	Taking speed into account.
**	- If not, move player according to player speed
** 2. Do the same for the y vector direction
**
** @param t_root *root - The root struct
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
** Funtion to move rforward
**
** 1. Check the map if the direction that we are about to move into is a wall.
**	Taking speed into account.
**	- If not, move player according to player speed
** 2. Do the same for the y vector direction
**
** @param t_root *root - The root struct
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