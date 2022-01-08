/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   root_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jng <jng@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:45:00 by jng               #+#    #+#             */
/*   Updated: 2022/01/08 11:50:44 by jng              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_root *root)
{
	root->game->player = malloc(sizeof(t_player));
	if (!root->game->player)
		quit_root(root, "Error: malloc() failure in root->game->player\n", 1);
	root->game->player->dir_vect.x = 0;
	root->game->player->dir_vect.y = 0;
	root->game->player->cam_plane_vect.x = 0;
	root->game->player->cam_plane_vect.y = 0;
	root->game->player->pos.x = 5;
	root->game->player->pos.y = 5;
	root->game->player->sens = 0.1;
	root->game->player->speed = 0.05;
	root->game->player->cam_height = 1.0;
}

void	init_controls(t_root *root)
{
	root->control = malloc(sizeof(t_control));
	if (!root->control)
		quit_root(root, "Error: malloc() failure in root->control\n", 1);
	root->control->look_left = 0;
	root->control->look_right = 0;
	root->control->look_up = 0;
	root->control->look_down = 0;
	root->control->move_left = 0;
	root->control->move_right = 0;
	root->control->move_fwd = 0;
	root->control->move_bwd = 0;
}
