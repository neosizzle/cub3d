#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <math.h>
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
	double	x;
	double	y;
}				t_coord;

/*
 Struct to store all raycasting related variable needed for rc calculation

 curr_x - current x index relative to the screen / how many pixels width
 map_x/y - current x/y index realtaive to the map
 cam_x - x- coordinate in camera space
 ray_dir_x/y = Ray x/y direction vector
 side_dist_x/y - length of ray from current position to next x or y-side
 delta_dist_x/y - length of ray from one x or y-side to next x or y-side
 step_x/y - The direction to step the vector in
 hit - determines wether or not a wall has been hit
 side - determines the side direction

*/
typedef struct s_ray
{
	int		curr_x;
	int		map_x;
	int		map_y;
	double	cam_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	prep_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}				t_ray;

/*
** Struct to store custom image properties
** 
** img_ptr - The image pointer mlx gives when creating new image
** data - The address adta given when calling mlx_get_img_addr
** bits_per_pixel - The amount of bits per pixel for colouring
** line length - is the number of bytes used to store one line of
**				 the image in memory (unused)
** endian -  tells you wether the pixel color in the image needs
** 				to be stored in little endian or big endian (unused)
** width - Width of image
** height - Height of image
*/
typedef struct s_image
{
	void	*img_ptr;
	char	*data;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_image;

//struct to store custom pixel properties
typedef struct s_pixel
{
	int	x;
	int	y;
	int	color;
}				t_pixel;

//struct to store custom line properties
typedef struct s_line
{
	t_pixel	*pixels;
}				t_line;

/*
** Struct to store player related data
**
** pos - position coordinate
** dir_vect - direction vector coordinate
** cam_plane_vect - camera plane vector coordinate
** speed - player movement speed
** sens - player turning sensitivity
*/
typedef struct s_player
{
	t_coord	pos;
	t_coord	dir_vect;
	t_coord	cam_plane_vect;
	double	speed;
	double	sens;
}	t_player;

//struct to store all game related data
typedef struct s_game
{
	char			**map;
	int				player_found;
	t_player		*player;
}				t_game;

/*
** Struct to store all mlx related data
**
** mlx - mlx pointer
** mlx_win - mlx window pointer
** mlx_img - mlx image pointer(unused)
** no_texture - The pointer to image struct for north texture
** so_texture - The pointer to image struct for south texture
** ea_texture - The pointer to image struct for east texture
** we_texture - The pointer to image struct for west texture
** frgb - floor color in int
** crgb - cel color in int
** game - pointer to game struct
*/
typedef struct s_root
{
	void			*mlx;
	void			*mlx_win;
	t_image			*mlx_img;
	t_image			*no_texture;
	t_image			*so_texture;
	t_image			*we_texture;
	t_image			*ea_texture;
	int				frgb;
	int				crgb;
	t_game			*game;
}				t_root;

//common utils
void		quit(char *str, int status);
void		quit_root(t_root *root, char *str, int status);
char		*get_next_line(int fd);
void		load_texture(t_root *root, t_image *img, char *path);
int			valid_cub(char *path);
int			get_map_length(char **map);
void		check_f_l(t_root *root, int i, int j);

//init functions
t_root		*init_root(char *str);
void		init_map(t_root *root, char *path);
void		init_player(t_root *root);

//format validation and utilities
int			validate_line(t_root *root, char **split);
void		validate_map(t_root *root);

//player utilities
void		set_camera(t_root *root, double d_y, double p_x, double p_y);

//render and draw functions
t_image		*generate_frame(t_root *root);
void		put_pixel(t_image *frame, int x, int y, int color);
void		put_frame(t_root *root, t_image *frame);
int			render(void *param);

//raycasting
void	raycasting(t_root *root, t_ray *ray);
void	prep_height(t_ray *ray, t_player *player);

//free functions
void		destroy_root(t_root *root);
void		free_split(char **split);

#endif