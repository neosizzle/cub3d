/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_executor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jng <jng@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:44:49 by jng               #+#    #+#             */
/*   Updated: 2022/01/07 14:44:52 by jng              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Executs evenents based on control struct
**
** @param t_root *root - The root struct
*/
void	event_executor(t_root *root)
{
	if (root->control->look_left)
		turn_left(root);
	if (root->control->look_right)
		turn_right(root);
	if (root->control->look_up)
		look_up(root);
	if (root->control->look_down)
		look_down(root);
	if (root->control->move_fwd)
		move_forward(root);
	if (root->control->move_bwd)
		move_backward(root);
	if (root->control->move_left)
		move_left(root);
	if (root->control->move_right)
		move_right(root);
}
