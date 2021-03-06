/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jng <jng@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:43:55 by jng               #+#    #+#             */
/*   Updated: 2022/01/08 11:43:56 by jng              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** This function will check for all textures are present before reading the map
**
** @param t_root * root - root struct
** @return int - 1 if OK, 0 if not
*/
static int	check_textures(t_root *root)
{
	if (!root->no_texture->img_ptr || !root->so_texture->img_ptr
		|| !root->we_texture->img_ptr
		|| !root->ea_texture->img_ptr || !root->frgb || !root->crgb)
		return (0);
	return (1);
}

/*
** This function wiil join line to buff, and get next line and store it on line
**
** @param char **buff - The pointer to buffer that you want line to append to
** @param char **line - The pointer to line that you want to read to
** @param int fd - The file descriptor to read from
*/
static void	read_to_buff(char **buff, char **line, int fd)
{
	char	*temp;

	temp = ft_strdup(*buff);
	free(*buff);
	*buff = ft_strjoin(temp, *line);
	free(temp);
	free(*line);
	*line = get_next_line(fd);
}

/*
** This function will specifically read the textures and data from 
** the opened fd
**
** 1. while the textures are not finished loading & there are still
** 	lines, keep reading
**	1. split string into array of strings with space delim
**	2. validate the current read line
**	3. check if the textures are finished loading
**	4. free buffer and gt next line
** 2. free line and return error if textures and not finished loading
**
** @param t_root * root - root struct
** @param int fd - opened file descriptor
*/
void	read_textures(t_root *root, int fd)
{
	int		finished_textures;
	char	*line;
	char	**split;

	finished_textures = 0;
	line = get_next_line(fd);
	while (!finished_textures && line)
	{
		split = ft_split(line, ' ');
		if (validate_line(root, split))
		{
			free(line);
			free_split(split);
			quit_root(root, "Error : texture/color validation failed", 1);
		}
		finished_textures = check_textures(root);
		free(line);
		free_split(split);
		line = get_next_line(fd);
	}
	free(line);
	if (!finished_textures)
		quit_root(root, "Error : config missing some required properties\n", 1);
}

/*
** This function will read the map data from an open fd
** and then call validation functions
**
** @param t_root *root - The root struct
** @param int fd - The open file descriptor
*/
void	read_map(t_root *root, int fd)
{
	char	*line;
	char	*buff;

	line = get_next_line(fd);
	while (line && !ft_strcmp(line, "\n"))
	{
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
	{
		close(fd);
		quit_root(root, "Error : No map found\n", 1);
	}
	buff = ft_bzero(0);
	while (line)
		read_to_buff(&buff, &line, fd);
	root->game->map = ft_split(buff, '\n');
	validate_map(root);
	free(buff);
}

/*
** This function initializes the map and reads the scene from a .cub file
**
** 1. Attempts to open a .cub file provided in path
** 2. Checks if file ends with .cub
** 3. Read and validate textures
** 4. Read and validate map
**
** @param t_root *root - The root struct
** @char *path - The file path to a .cub file
*/
void	init_map(t_root *root, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0 || valid_cub(path))
	{
		close(fd);
		quit_root(root, "Error : invalid fd open()\n", 1);
	}
	read_textures(root, fd);
	read_map(root, fd);
}
