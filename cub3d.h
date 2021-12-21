#ifndef __CUB3D__H__
#define __CUB3D__H__
# define WIN_HEIGHT 768
# define WIN_WIDTH 1360
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>
# include <mlx.h>
# include <mlx_int.h>
# include "./libft/libft.h"

//struct to store the x y coords of an obj
typedef struct s_coord
{
	int				x;
	int				y;
}				t_coord;

//struct to store all game related data
typedef struct s_game
{
	char			**map;
}				t_game;

//struct to store all mlx related data
typedef struct s_root
{
	void			*mlx;
	void			*mlx_win;
	void			*mlx_img;
	t_game			*game;
}				t_root;

#endif  //!__CUB3D__H__