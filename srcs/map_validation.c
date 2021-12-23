#include "cub3d.h"

/*
 Function that load the textures according to the identifier
*/
static int	process_textures(t_root *root, char *iden ,char **split)
{
	if (!ft_strcmp(iden , "NO")) 
		load_texture(root, &(root->no_texture), split[1]);
	else if (!ft_strcmp(iden, "SO"))
		load_texture(root, &(root->so_texture), split[1]);
	else if (!ft_strcmp(iden, "WE"))
		load_texture(root, &(root->we_texture), split[1]);
	else if (!ft_strcmp(iden, "EA"))
		load_texture(root, &(root->ea_texture), split[1]);
	else
		return (1);
	return (0);
}

static int	process_color(t_root *root, char *iden, char **split)
{
	if (!ft_strcmp(iden , "F"))
		printf("floor color\n");
	else if (!ft_strcmp(iden, "C"))
		printf("ceil color\n");
	else
		return (1);
	return (0);
}

/*
 Function that takes an array of strings and validate the format

 1. Compares the first element of split
  1. if its NO, SO, WE or EA, process the textures and return the functions ret value
  2. if its F or C, process the colors and return the functions ret value
  3. If is a newline, do nth and return zero
 2. return 1 if anything else

 @param t_root * root - root struct
 @param char **split - array of strings spliited with space char as delim
 @return int - 0 if OK and nonzero if not
*/
int	validate_line(t_root *root, char **split)
{
	if (!ft_strcmp(split[0] , "NO") || !ft_strcmp(split[0] , "SO") ||
		!ft_strcmp(split[0] , "WE") || !ft_strcmp(split[0] , "EA"))
		return (process_textures(root, split[0], split));
	else if (!ft_strcmp(split[0], "F") || !ft_strcmp(split[0], "C"))
		return printf("Color process...\n");
	else if (!ft_strcmp(split[0], "\n"))
		return (0);

	return (1);
}