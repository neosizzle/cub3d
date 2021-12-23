#include "cub3d.h"

//This file contains map-related functions

/*
** This function checks if file path ends with .cub
**
** @param char *path - file path
** @return int - 0 if OK
*/
static int	valid_cub(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (!path)
		quit("Error : invalid .cub file\n", 1);
	if (len < 5)
		quit("Error : invalid .cub file\n", 1);
	if (ft_strncmp(path + len - 4, ".cub", len) != 0)
		quit("Error : invalid .cub file\n", 1);
	return (0);
}

/*
** This function will check for all textures are present before reading the map
**
** @param t_root * root - root struct
** @return int - 1 if OK, 0 if not
*/
static int	check_textures(t_root *root)
{
	if (!root->no_texture || !root->so_texture || !root->we_texture ||
		!root->ea_texture || !root->frgb || !root->crgb)
		return 0;
	return 1;
}

/*
 This function will specifically read the textures and data from 
 the opened fd

 1. while the textures are not finished loading, keep reading
 	1.get next line from fd
	2. if line is null, means something is missing, exit.

 @param t_root * root - root struct
 @param int fd - opened file descriptor
*/
void	read_textures(t_root *root, int fd)
{
	int		finished_textures;
	char	*line;
	char	**split;

	finished_textures = 0;
	while (!finished_textures)
	{
		line = get_next_line(fd);
		if (!line)
		{
			destroy_root(root);
			quit("Error : Bad config\n", 1);
		}
		split = ft_split(line, ' ');
		if (validate_line(root, split))
		{
			destroy_root(root);
			quit("Error : Bad config\n", 1);
		}
		finished_textures = check_textures(root);
		free(line);
		free(split);
	}
	
}

// void	read_map(t_root *root, int fd)
// {

// }

//intialize map and config
//read textures & colors
//read colors
//read map
void	init_map(t_root *root, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0 || valid_cub(path))
	{
		close(fd);
		destroy_root(root);
		quit("Error: invalid fd open()\n", 1);
	}
	read_textures(root, fd);
	//read_map(root, fd);
}
