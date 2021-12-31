#include "cub3d.h"

/*
** Main render function
**
** 1. initialize ray and root
** 2. start raycasting process
** 3. put image to window
** 4. free ray struct
*/
int	render(void *param)
{
	t_root *root;
	t_ray	*ray;

	root = (t_root *)param;
	ray = malloc(sizeof(t_ray));
	ft_bzero_inplace(ray, sizeof(t_ray));
	while (ray->curr_x < WIN_WIDTH)
		raycasting(root, ray);
	//put img to win here
	free(ray);
	return (0);
}