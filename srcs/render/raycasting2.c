/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jng <jng@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:57:18 by jng               #+#    #+#             */
/*   Updated: 2022/01/07 14:57:20 by jng              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Function that determines perpendicular distance
**	and sets line draw start and end
**
** 1. obtain the distance between the intersect point and
**	the perpendicular wall / camera
** 2. obtain line height based on screen height
** 3. calculate lowest and highest drawable pixel
**
** @param t_ray *ray - the ray struct
** @param t_player *player - the player struct
** @param t_root *root - the root struct
**
*/
void	prep_height(t_ray *ray, t_player *player)
{
	if (ray->side == WEST || ray->side == EAST)
		ray->prep_wall_dist = ((double) ray->map_x - player->pos.x
				+ (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->prep_wall_dist = ((double) ray->map_y - player->pos.y
				+ (1 - ray->step_y) / 2) / ray->ray_dir_y;
	ray->line_height = WIN_HEIGHT / ray->prep_wall_dist;
	ray->draw_start = -ray->line_height / 2
		+ ((WIN_HEIGHT / 2) * player->cam_height);
	if (ray->draw_start <= 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2
		+ ((WIN_HEIGHT / 2) * player->cam_height);
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
}
