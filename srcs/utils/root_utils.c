/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   root_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jng <jng@student.42kl.edu>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:44:44 by jng               #+#    #+#             */
/*   Updated: 2022/01/24 14:14:20 by jng              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/*
** Function that initializes renderer requried objects
**
** 1. Initializes mlxinit()
** 2. Initializes mlx_new_window()
** 3. Initializes mlx_img (our main frames)
** 4. Set mlx_img metadata
**
** @param t_root *root - The root struct
*/
static void	init_renderer(t_root *root)
{
	root->mlx = mlx_init();
	if (!root->mlx)
		quit("Error : mlx_init() failure\n", 1);
	root->mlx_win
		= mlx_new_window(root->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!root->mlx_win)
		quit("Error : mlx_init() failure\n", 1);
	root->mlx_img->img_ptr = mlx_new_image(root->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!root->mlx_img->img_ptr)
		quit_root(root, "Error: mlx_new_image() failure\n", 1);
	root->mlx_img->width = WIN_WIDTH;
	root->mlx_img->height = WIN_HEIGHT;
	root->mlx_img->data = mlx_get_data_addr(root->mlx_img->img_ptr,
			&root->mlx_img->bits_per_pixel,
			&root->mlx_img->line_length, &root->mlx_img->endian);
}

/*
** Function that laods xpm texture file into image pointer
**
** 1. Call mlx_xpm_file_to_image() to obtain image pointer
** 2. Set image metadata to the rest of the struct
**
** @param t_root *root - The root struct
** @param t_img *img - The image object to be initialized
** @param char *path - The file path to the xpm file
*/
void	load_texture(t_root *root, t_image *img, char *path)
{
	int	width;
	int	height;

	img->img_ptr = mlx_xpm_file_to_image(root->mlx, path, &width, &height);
	if (!img->img_ptr)
		quit_root(root, "Error: mlx_xpm_file_to_image() failure\n", 1);
	img->width = width;
	img->height = height;
	img->data = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

/*
** Initializes all root textores to 0
*/
static void	init_textures(t_root *root)
{
	root->mlx_img = malloc(sizeof(t_image));
	root->no_texture = malloc(sizeof(t_image));
	root->so_texture = malloc(sizeof(t_image));
	root->ea_texture = malloc(sizeof(t_image));
	root->we_texture = malloc(sizeof(t_image));
	root->frgb = 0;
	root->crgb = 0;
	ft_bzero_inplace(root->mlx_img, sizeof(t_image));
	ft_bzero_inplace(root->no_texture, sizeof(t_image));
	ft_bzero_inplace(root->so_texture, sizeof(t_image));
	ft_bzero_inplace(root->ea_texture, sizeof(t_image));
	ft_bzero_inplace(root->we_texture, sizeof(t_image));
}

/*
** Function to call seperate initializers
**
** 1. Initialize root textures
** 2. Initialize renderer data
** 3. Initialize game data
**
** @param char *path - The file path to the .cub file
** @return t_root *root - the root struct
*/
t_root	*init_root(char *path)
{
	t_root	*res;

	res = malloc(sizeof(t_root));
	init_textures(res);
	init_renderer(res);
	init_game(res, path);
	init_controls(res);
	return (res);
}
