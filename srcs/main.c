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

	/* Test shit*/

	//write a line
	// t_image	*testframe;
	// testframe = generate_frame(root);
	// put_pixel(testframe, 0, 0, 0x00FF0000);
	// int	tempy = -1;
	// while (++tempy < WIN_HEIGHT)
	// 	put_pixel(testframe, 0, tempy, 0x00FF0000);
	// put_frame(root, testframe);

	//write an image using coords
	

	/* Test shit*/

	mlx_loop(root->mlx);
	return (0);
}
