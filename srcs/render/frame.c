#include "cub3d.h"

t_image	*generate_frame(t_root *root)
{
	t_image *frame;

	frame = malloc(sizeof(t_image));
	frame->img_ptr = mlx_new_image(root->mlx, WIN_WIDTH, WIN_HEIGHT);
	frame->bits_per_pixel = 0;
	frame->line_length = 0;
	frame->endian = 0;
	frame->data = 0;
	frame->data = mlx_get_data_addr(frame->img_ptr, &(frame->bits_per_pixel), &(frame->line_length),
								&(frame->endian));

	return (frame);
}

void	put_pixel(t_image *frame, int x, int y, int color)
{
	char	*dst;

	dst = frame->data + (y * frame->line_length + x * (frame->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	put_frame(t_root *root, t_image *frame)
{
	mlx_put_image_to_window(root->mlx, root->mlx_win, frame->img_ptr, 0, 0);
}