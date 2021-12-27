#include "cub3d.h"

/*
 Function to get the length of a 2d array
*/
int	get_map_length(char **map)
{
	int	i;

	i = -1;
	while (map[++i]){}
	return (i);
}

/*
 Function that checks for all 1s in a line 
*/
void	check_f_l(t_root *root, int i, int j)
{
	--j;
	// printf("Checking fl..\n");
	while (root->game->map[i][++j])
	{
		if (root->game->map[i][j] != '1' && root->game->map[i][j] != ' ')
		{
			// printf(" invalid fl\n");
			destroy_root(root);
			quit("Error : Map not closed border R1\n", 1);
		}
	}
	
}