/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jng <jng@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:44:33 by jng               #+#    #+#             */
/*   Updated: 2022/01/08 11:49:59 by jng              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//frees arr of strings
void	free_split(char **split)
{
	char	*temp;
	char	**copy;	

	copy = split;
	while (*split)
	{
		temp = *split;
		split++;
		free(temp);
	}
	free(copy);
}

//frees game elements
static void	free_game(t_root *root)
{
	if (root->game->map)
		free_split(root->game->map);
	if (root->game->player)
		free(root->game->player);
	free(root->game);
}

//this frees the img ptr inside img struct and frees the struct itself
// if (img->data && img->img_ptr)
// 	mlx_destroy_image(root->mlx, img->img_ptr); (will segfault)
static void	destroy_image(t_root *root, t_image *img)
{
	if (img->data && img->img_ptr)
		mlx_destroy_image(root->mlx, img->img_ptr);
	(void) root;
	free(img);
}

//frees a root struct
void	destroy_root(t_root *root)
{
	if (root->no_texture)
		destroy_image(root->mlx, root->no_texture);
	if (root->so_texture)
		destroy_image(root->mlx, root->so_texture);
	if (root->ea_texture)
		destroy_image(root->mlx, root->ea_texture);
	if (root->we_texture)
		destroy_image(root->mlx, root->we_texture);
	if (root->mlx_img)
		destroy_image(root->mlx, root->mlx_img);
	mlx_destroy_window(root->mlx, root->mlx_win);
	free(root->mlx);
	free_game(root);
	free(root);
}
