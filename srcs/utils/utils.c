/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jng <jng@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:45:07 by jng               #+#    #+#             */
/*   Updated: 2022/01/08 11:50:44 by jng              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//function to print a string and quit program
void	quit(char *str, int status)
{
	ft_putstr_fd(str, 0);
	exit(status);
}

//function to free root struct then quit the program
// apparently i dont need to destroy_root(root); ???
void	quit_root(t_root *root, char *str, int status)
{
	(void) root;
	quit(str, status);
}

/*
** This function checks if file path ends with .cub
**
** @param char *path - file path
** @return int - 0 if OK
*/
int	valid_cub(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (!path)
		quit("Error : invalid .cub file\n", 1);
	if (len < 5)
		quit("Error : invalid .cub file\n", 1);
	if (ft_strncmp(path + len - 4, ".cub", len) != 0)
		quit("Error : invalid .cub file\n", 1);
	return (0);
}
