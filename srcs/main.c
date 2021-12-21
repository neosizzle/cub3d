#include "cub3d.h"

//function to print a string and quit program
void	quit(char *str, int status)
{
	ft_putstr_fd(str, 0);
	exit(status);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		quit("Usage ./cub3d [path_to_map]\n",1);
	(void) argv;
	return 0;
}
