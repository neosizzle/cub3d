#include "cub3d.h"

void	validate_map(t_root *root)
{
	int		i;
	int		j;
	int		len;
	char	**map;

	map = root->game->map;
	len = get_map_length(map);
	i = -1;
	while (++i < len)
	{
		printf("Currently processing i : %d\n", i);
		j = -1;
		//clear whitespace
		while (map[i][++j] && map[i][j] == ' '){}
		
		//check for for last line
		if (i == 0 || i == len - 1)
		{
			check_f_l(root, i, j);
			continue ;
		}

		//clear rest of the chars
		//first char 1
		if (map[i][j--] != '1')
			quit("Error : Map leftside not closed R2\n", 1);
		if (map[i][ft_strlen(map[i]) - 1] != '1')
			quit("Error : Map right not closed R2\n", 1);
		while (map[i][++j])
		{
			//add symbol validation
			//add player validation
			if (ft_strlen(map[i]) > ft_strlen(map[i - 1]) && j >= (int)ft_strlen(map[i - 1]))
			{
				if (map[i][j] != '1')
					quit("Error : Map not closed multilvl R3\n", 1);
			}
			if (j < (int)ft_strlen(map[i - 1]) && map[i - 1][j] == ' ')
			{
				if (map[i][j] != '1')
					quit("Error : Map not closed multilvl R4\n", 1);
			}
			if (ft_strlen(map[i]) > ft_strlen(map[i + 1]) && j >= (int)ft_strlen(map[i + 1]))
			{
				if (map[i][j] != '1')
					quit("Error : Map not closed multilvl R5\n", 1);
			}
			if (j < (int)ft_strlen(map[i + 1]) && map[i + 1][j] == ' ')
			{
				if (map[i][j] != '1')
					quit("Error : Map not closed multilvl R6\n", 1);
			}	
		}
	}
	
}