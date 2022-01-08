/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jng <jng@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:51:14 by jng               #+#    #+#             */
/*   Updated: 2022/01/08 11:51:15 by jng              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include "./libft/libft.h"
# define WIN_HEIGHT 400
# define WIN_WIDTH 800
# define NORTH 1
# define SOUTH 2
# define EAST 3
# define WEST 4
# define ESCAPE_KEY 53
# define UP_KEY 126
# define DOWN_KEY 125
# define RIGHT_KEY 124
# define LEFT_KEY 123
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2

// linux keybinds
// # define ESCAPE_KEY 65307
// # define UP_KEY 65362
// # define DOWN_KEY 65364
// # define RIGHT_KEY 65363
// # define LEFT_KEY 65361
// # define W_KEY 119
// # define A_KEY 97
// # define S_KEY 115
// # define D_KEY 100

//struct to store the x y coords of an obj
typedef struct s_coord
{
	double	x;
	double	y;
}				t_coord;

/*
** Struct to store all raycasting related variable needed for rc calculation
**
** curr_x - current x index relative to the screen / how many pixels width
** map_x/y - current x/y index realtaive to the map
** cam_x - x- coordinate in camera space
** ray_dir_x/y = Ray x/y direction vector
** side_dist_x/y - length of ray from current position to next x or y-side
** delta_dist_x/y - length of ray from one x or y-side to next x or y-side
** step_x/y - The direction to step the vector in
** hit - determines wether or not a wall has been hit
** side - determines the side direction
** line_height - the height of texture to draw
** draw_start - the index of initial draw value
** draw_end - the index of end draw value
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

/*
** Struct to store line properties to draw on screen
**
** x - the x coordinate of lien relative to screen
** y - the current pixel index of the line 
** y0 - y start index of drawing
** y1 - y end index of drawing
** tex_x - x coordinate of texture to draw
** tex_y - y coordinate of texture to draw
*/
typedef struct s_line
{
	int	x;
	int	y;
	int	y0;
	int	y1;
	int	tex_x;
	int	tex_y;
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
	double	cam_height;
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
 Struct to store all player control related data
*/
typedef struct s_control
{
	int	look_left;
	int	look_right;
	int	look_up;
	int	look_down;
	int	move_left;
	int	move_right;
	int	move_fwd;
	int	move_bwd;
}				t_control;

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
	t_control		*control;
}				t_root;

//common utils
void		quit(char *str, int status);
void		quit_root(t_root *root, char *str, int status);
char		*get_next_line(int fd);
void		load_texture(t_root *root, t_image *img, char *path);
int			valid_cub(char *path);
int			get_map_length(char **map);
int			check_f_l(t_root *root, int i, int j);

//init functions
t_root		*init_root(char *str);
void		init_map(t_root *root, char *path);
void		init_player(t_root *root);
void		init_controls(t_root *root);

//format validation and utilities
int			validate_line(t_root *root, char **split);
void		validate_map(t_root *root);
void		call_validations(t_root *root, char **map, int i, int j);

//player utilities
void		set_camera(t_root *root, double d_y, double p_x, double p_y);
void		turn_left(t_root *root);
void		turn_right(t_root *root);
void		look_up(t_root *root);
void		look_down(t_root *root);
void		move_forward(t_root *root);
void		move_backward(t_root *root);
void		move_left(t_root *root);
void		move_right(t_root *root);

//render and draw functions
t_image		*generate_frame(t_root *root);
void		put_pixel(t_image *frame, int x, int y, int color);
void		put_frame(t_root *root, t_image *frame);
int			render(void *param);
void		draw_textures(t_root *root, t_ray *ray, t_player *player);
void		draw_texture_image(t_root *root,
				t_ray *ray,
				t_line *line,
				t_image *img);
void		paint_line(t_root *root, t_line *line, int rgb);

//raycasting
void		raycasting(t_root *root, t_ray *ray);
void		prep_height(t_ray *ray, t_player *player);

//event / key handling
int			handle_key_press(int key, t_root *root);
int			handle_key_release(int key, t_root *root);
void		event_executor(t_root *root);

//free functions
void		destroy_root(t_root *root);
void		free_split(char **split);

#endif
