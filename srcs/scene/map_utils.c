/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jng <jng@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:33:20 by jng               #+#    #+#             */
/*   Updated: 2022/01/08 11:36:05 by jng              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Function to get the length of a 2d array
**
** @param char **map - the 2d array in question
** @return int i - the length of map
*/
int	get_map_length(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
	{
	}
	return (i);
}

/*
** Function that checks for all 1s in a line 
**
** @param t_root *root - The root struct
** @param int i - The current row of the map
** @param int j - The current column of the map
** @return int res - 0 if ok
*/
int	check_f_l(t_root *root, int i, int j)
{
	--j;
	while (root->game->map[i][++j])
	{
		if (root->game->map[i][j] != '1' && root->game->map[i][j] != ' ')
			quit_root(root, "Error : Map not closed border R1\n", 1);
	}
	return (0);
}

/*
** Function that calls validate symbols, root, player
**
** @param t_root *root - The root struct
** @param int i - The current row of the map
** @param int j - The current column of the map
*/
void	call_validations(t_root *root, char **map, int i, int j)
{
	validate_symbols(root, map[i]);
	validate_player(root, map, i, j);
	validate_borders(map, i, j);
}
