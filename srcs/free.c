#include "cub3d.h"

//this file contains the fcuntions for freeing memory
void	destroy_root(t_root *root)
{
	free(root->game);
	free(root);
}