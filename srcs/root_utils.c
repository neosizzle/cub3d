#include "cub3d.h"

//This file will store all root related functions

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

//shell fucntion to call all parts of initializers
t_root *init_root(char *path)
{
	t_root *res;

	res = malloc(sizeof(t_root));
	init_renderer(res);
	(void) path;
	//init_game(res);
	//init_texture(res);
	return res;
}