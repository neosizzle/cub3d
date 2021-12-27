#include "cub3d.h"

/*
** Function that checks for allowed symbols
**
** @param t_root * root - The root struct
** @param char *line - The current map row
*/
static void	validate_symbols(t_root *root, char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'N' &&
			line[i] != 'S' && line[i] != 'E' && line[i] != 'W' &&
			line[i] != ' ')
		{
			destroy_root(root);
			quit("Error : Invalid map symbol\n", 1);
		}
	}
}

/*
** Function that checks for borders
**
** 1. Check for top row length > curr row length && curr idx > top strlen
** 2. Check for current col top is a space
** 3. Check for bottom row length > curr row length && curr idx > bottom strlen
** 4. Check for current col bot is a space
**
** @param char **map - the 2d map array
** @param int i - the current row 
** @param int j - the current column
*/
static void	validate_borders(char **map, int i, int j)
{
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

/*
** Function that takes a roto struct and validates a map.
** Parses the map line by line.
** Exits if an invalid map is found
**
** 1. Start to parse the map line by line
**	1. start parsing from first column
**	2. ignore spaces
**	3. check for first and last line should contain all ones or spaces (small bug)
**	4. check for closed borders in first and last column
**	5. additional border checking for different length edges
**
** @param t_root *root - the root struct
*/
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
		//printf("Currently processing i : %d\n", i);
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

			validate_symbols(root, map[i]);
			//add player validation
			validate_borders(map, i, j);
		}
	}
	
}