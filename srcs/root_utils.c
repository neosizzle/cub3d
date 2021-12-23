#include "cub3d.h"

//This file will store all root related functions

//will init game data
/*
** player.x and y -> player position coordinates
** dir_vect.x and y -> player direction vector
** cam_plane_vect.x and y ->camera plane vector
** other stuff will be added here also.....
*/
static void	init_game(t_root *root, char *path)
{
	root->game = (t_game *)malloc(sizeof(t_game));
	if (!root->game)
	{
		destroy_root(root);
		quit("Error: malloc() failure in root->game\n", 1);
	}
	root->game->player.x = 1;
	root->game->player.y = 1;
	root->game->dir_vect.x = -1;
	root->game->dir_vect.y = 0;
	root->game->cam_plane_vect.x = 0;
	root->game->cam_plane_vect.y = 0.66; 
	init_map(root, path);
}

//function to initialize renderer object
static void	init_renderer(t_root *root)
{
	root->mlx = mlx_init();
	if (!root->mlx)
		quit("Error : mlx_init() failure\n", 1);
	root->mlx_win
		= mlx_new_window(root->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	if (!root->mlx_win)
		quit("Error : mlx_init() failure\n", 1);
}

//function to load xpm texture file into image pointer
void	load_texture(t_root *root, void **img, char *path)
{
	int	width;
	int	height;

	*img = mlx_xpm_file_to_image(root->mlx, path, &width, &height);
	if (!img)
		error("Error: mlx_xpm_file_to_image() failure\n");
}

//shell fucntion to call all parts of initializers.
t_root *init_root(char *path)
{
	t_root *res;

	res = malloc(sizeof(t_root));
	init_renderer(res);
	init_game(res, path);
	//init_texture(res);
	return res;
}