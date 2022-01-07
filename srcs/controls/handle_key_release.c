/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_release.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jng <jng@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:45:02 by jng               #+#    #+#             */
/*   Updated: 2022/01/07 14:48:50 by jng              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Sets control struct accordingly to key releases
**
** @param int key - The key described as integer
** @param t_root *root - The root struct
** @return int status
*/
int	handle_key_release(int key, t_root *root)
{
	if (key == LEFT_KEY)
		root->control->look_left = 0;
	if (key == RIGHT_KEY)
		root->control->look_right = 0;
	if (key == W_KEY)
		root->control->move_fwd = 0;
	if (key == S_KEY)
		root->control->move_bwd = 0;
	if (key == A_KEY)
		root->control->move_left = 0;
	if (key == D_KEY)
		root->control->move_right = 0;
	if (key == UP_KEY)
		root->control->look_up = 0;
	if (key == DOWN_KEY)
		root->control->look_down = 0;
	return (0);
}
