#include "cub3d.h"

/*
** Function that load the textures according to the identifier
**
** @param t_root *root - The root struct
** @param char *iden - The direction identifier
** @char **split - The entire string array containing
**  identifier and path to texture
*/
static int	process_textures(t_root *root, char *iden ,char **split)
{
	char *trimmed_nl;

	trimmed_nl = ft_strtrim(split[1], "\n");
	if (!ft_strcmp(iden , "NO"))
		load_texture(root, root->no_texture, trimmed_nl);
	else if (!ft_strcmp(iden, "SO"))
		load_texture(root, root->so_texture, trimmed_nl);
	else if (!ft_strcmp(iden, "WE"))
		load_texture(root, root->we_texture, trimmed_nl);
	else if (!ft_strcmp(iden, "EA"))
		load_texture(root, root->ea_texture, trimmed_nl);
	else
	{
		free(trimmed_nl);
		return (1);
	}
	free(trimmed_nl);
	return (0);
}

/*
** Function that sets hex colors inside root vars
**
** @param t_root *root - The root struct
** @param char *iden - The floor or ceil identifier
** @char **split - The entire string array containing
**  identifier and path to texture
*/
static int	process_color(t_root *root, char *iden, char **split)
{
	char	**colors;
	int		r;
	int		g;
	int		b;

	colors = ft_split(split[1], ',');
	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	free_split(colors);
	if (!ft_strcmp(iden , "F"))
		root->frgb = (1 << 24 | r << 16 | g << 8 | b);
	else if (!ft_strcmp(iden, "C"))
		root->crgb = (1 << 24 | r << 16 | g << 8 | b);
	else
		return (1);
	return (0);
}

/*
** Function that takes an array of strings and validate the texture format
**
** 1. Compares the first element of split
**  1. if its NO, SO, WE or EA, process the textures and return the functions ret value
**  2. if its F or C, process the colors and return the functions ret value
**  3. If is a newline, do nth and return zero
** 2. return 1 if anything else
**
** @param t_root * root - root struct
** @param char **split - array of strings spliited with space char as delim
** @return int - 0 if OK and nonzero if not
*/
int	validate_line(t_root *root, char **split)
{
	if (!ft_strcmp(split[0] , "NO") || !ft_strcmp(split[0] , "SO") ||
		!ft_strcmp(split[0] , "WE") || !ft_strcmp(split[0] , "EA"))
		return (process_textures(root, split[0], split));
	else if (!ft_strcmp(split[0], "F") || !ft_strcmp(split[0], "C"))
		return (process_color(root, split[0], split));
	else if (!ft_strcmp(split[0], "\n"))
		return (0);
	return (1);
}