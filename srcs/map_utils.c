#include "cub3d.h"

//This file contains map-related functions

void	init_map(t_root *root, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		{
		close(fd);
		destroy_root(root);
		quit("Error: invalid fd open()\n", 1);
	}
}