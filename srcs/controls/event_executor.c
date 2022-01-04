#include "cub3d.h"

/*
 Executs evenents based on control struct
*/
void	event_executor(t_root *root)
{
	if (root->control->look_left)
		turn_left(root);
	if (root->control->look_right)
		turn_right(root);
}