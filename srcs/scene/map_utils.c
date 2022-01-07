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
*/
void	check_f_l(t_root *root, int i, int j)
{
	--j;
	while (root->game->map[i][++j])
	{
		if (root->game->map[i][j] != '1' && root->game->map[i][j] != ' ')
			quit_root(root, "Error : Map not closed border R1\n", 1);
	}
}
