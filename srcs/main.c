/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jng <jng@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:45:16 by jng               #+#    #+#             */
/*   Updated: 2022/01/09 10:28:52 by jng              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** This function exits the game
*/
int	game_exit(void)
{
	quit("Game exit\n", 0);
	return (0);
}

/*
** Main function
**
** 1. Check for argc, only 1 arg is allowed
** 2. Initialize roto struct
** 3. Hook close window button to game exit
** 4. Hook keypress events to handle_key_press()
** 5. Hook keyrelease events to handle_key_release()
** 6. Hook the main loop to render()
** 7. Start looping
*/
int	main(int argc, char **argv)
{
	t_root	*root;

	if (argc != 2)
		quit("Usage ./cub3d [path_to_map]\n", 1);
	root = init_root(argv[1]);
	mlx_hook(root->mlx_win, 17, 0, game_exit, root);
	mlx_hook(root->mlx_win, 2, 1L << 0, handle_key_press, root);
	mlx_hook(root->mlx_win, 3, 1L << 1, handle_key_release, root);
	mlx_loop_hook(root->mlx, render, root);
	mlx_loop(root->mlx);
	return (0);
}
