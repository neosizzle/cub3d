#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>
# include <mlx.h>
# include <mlx_int.h>
# include "./libft/libft.h"
# define WIN_HEIGHT 768
# define WIN_WIDTH 1360

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
	t_coord			player;
	t_coord			dir_vect;
	t_coord			cam_plane_vect;

}				t_game;

//struct to store all mlx related data
typedef struct s_root
{
	void			*mlx;
	void			*mlx_win;
	void			*mlx_img;
	void			*no_texture;
	void			*so_texture;
	void			*we_texture;
	void			*ea_texture;
	int				frgb;
	int				crgb;
	t_game			*game;
}				t_root;

//common utils
void	quit(char *str, int status);
char	*get_next_line(int fd);
void	load_texture(t_root *root, void **img, char *path);

//init functions
t_root	*init_root(char *str);
void	init_map(t_root *root, char *path);

//format validation and utilities
int		validate_line(t_root *root, char **split);

//free functions
void	destroy_root(t_root *root);

#endif