#include "cub3d.h"

//function to print a string and quit program
void	quit(char *str, int status)
{
	ft_putstr_fd(str, 0);
	exit(status);
}

/*
** This function checks if file path ends with .cub
**
** @param char *path - file path
** @return int - 0 if OK
*/
int	valid_cub(char *path)
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