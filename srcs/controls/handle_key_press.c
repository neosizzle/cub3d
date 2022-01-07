#include "cub3d.h"

/*
** Sets control struct accordingly to key presses
**
** @param int key - The key described as integer
** @param t_root *root - The root struct
** @return int status
*/
int	handle_key_press(int key, t_root *root)
{
	if (key == ESCAPE_KEY)
		quit("Game exit\n",0);
	if (key == LEFT_KEY)
		root->control->look_left = 1;
	if (key == RIGHT_KEY)
		root->control->look_right = 1;
	if (key == W_KEY)
		root->control->move_fwd = 1;
	if (key == S_KEY)
		root->control->move_bwd = 1;
	if (key == A_KEY)
		root->control->move_left = 1;
	if (key == D_KEY)
		root->control->move_right = 1;
	if (key == UP_KEY)
		root->control->look_up = 1;
	if (key == DOWN_KEY)
		root->control->look_down = 1;
	return (0);
}

