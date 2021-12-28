#include "cub3d.h"

//This file will store all root related functions

/*
** This function will init game data
**
** 1. initializes map and player found
** 2. initializes player
** 3. initializes map
**
** @param t_root *root - the Root struct
** @param char *path - The .cub file path
*/ 
static void	init_game(t_root *root, char *path)
{
	root->game = (t_game *)malloc(sizeof(t_game));
	if (!root->game)
		quit_root(root, "Error: malloc() failure in root->game\n", 1);
	root->game->map = 0;
	root->game->player_found = 0;
	init_player(root);
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
void	load_texture(t_root *root, t_image *img, char *path)
{
	int	width;
	int	height;

	img->img_ptr = mlx_xpm_file_to_image(root->mlx, path, &width, &height);
	if (!img->img_ptr)
	{
		destroy_root(root);
		quit("Error: mlx_xpm_file_to_image() failure\n", 1);
	}
	img->width = width;
	img->height = height;
	img->data = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel, &img->line_length, &img->endian);
}

/*
 Initializes all root textures to 0
*/
static void	init_textures(t_root *root)
{
	root->no_texture = malloc(sizeof(t_image));
	root->so_texture = malloc(sizeof(t_image));
	root->ea_texture = malloc(sizeof(t_image));
	root->we_texture = malloc(sizeof(t_image));
	root->no_texture->img_ptr = 0;
	root->so_texture->img_ptr = 0;
	root->ea_texture->img_ptr = 0;
	root->we_texture->img_ptr = 0;
	root->frgb = 0;
	root->crgb = 0;
}

//shell fucntion to call all parts of initializers.
t_root *init_root(char *path)
{
	t_root *res;

	res = malloc(sizeof(t_root));

	init_textures(res);
	init_renderer(res);
	init_game(res, path);
	return res;
}