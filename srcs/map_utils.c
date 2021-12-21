#include "cub3d.h"

//This file contains map-related functions
int	process_map(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		{
		close(fd);
		//destroy_root(root);
		//error("Error: invalid fd open()\n");
	}
	return 1;
}