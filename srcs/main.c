#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_root	*root;

	if (argc != 2)
		quit("Usage ./cub3d [path_to_map]\n",1);
	root = init_root(argv[1]);
	(void) root;
	return 0;
}
