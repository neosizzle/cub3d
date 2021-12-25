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
static void free_game(t_root *root)
{
	if (root->game->map)
		free_split(root->game->map);
	free(root->game);
}

//this file contains the fcuntions for freeing memory
void	destroy_root(t_root *root)
{
	if (root->no_texture)
		mlx_destroy_image(root->mlx, root->no_texture);
	if (root->so_texture)
		mlx_destroy_image(root->mlx, root->so_texture);
	if (root->ea_texture)
		mlx_destroy_image(root->mlx, root->ea_texture);
	if (root->we_texture)
		mlx_destroy_image(root->mlx, root->we_texture);
	mlx_destroy_window(root->mlx, root->mlx_win);
	free(root->mlx);
	free_game(root);
	free(root);
}