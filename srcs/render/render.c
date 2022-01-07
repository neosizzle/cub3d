/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jng <jng@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:57:45 by jng               #+#    #+#             */
/*   Updated: 2022/01/07 14:57:46 by jng              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Main render function
**
** 1. initialize ray and root
** 2. start raycasting process
** 3. put image to window
** 4. free ray struct
** 5. listen for events
*/
int	render(void *param)
{
	t_root	*root;
	t_ray	*ray;

	root = (t_root *)param;
	ray = malloc(sizeof(t_ray));
	ft_bzero_inplace(ray, sizeof(t_ray));
	while (ray->curr_x < WIN_WIDTH)
		raycasting(root, ray);
	mlx_put_image_to_window(root->mlx, root->mlx_win,
		root->mlx_img->img_ptr, 0, 0);
	free(ray);
	event_executor(root);
	return (0);
}
