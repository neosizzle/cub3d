#include "cub3d.h"
int	game_exit(void)
{
	quit("Game exit\n", 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_root	*root;

	if (argc != 2)
		quit("Usage ./cub3d [path_to_map]\n", 1);
	root = init_root(argv[1]);
	mlx_hook(root->mlx_win, 17, 0, game_exit, root);
	mlx_loop(root->mlx);
	return (0);
}
