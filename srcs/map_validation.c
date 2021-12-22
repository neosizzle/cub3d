#include "cub3d.h"

/*
 Function that takes an array of strings and validate the format
*/
int	validate_line(t_root *root, char **split)
{
	if (ft_strcmp(split[0] , "NO") || ft_strcmp(split[0] , "SO") ||
		ft_strcmp(split[0] , "WE") || ft_strcmp(split[0] , "EA") ||
		ft_strcmp(split[0] , "C") || ft_strcmp(split[0] , "F") ||
		ft_strcmp(split[0] , "\n"))
		return 1;

	return 0;
}