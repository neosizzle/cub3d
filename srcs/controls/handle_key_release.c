#include "cub3d.h"

/*
 Sets control struct accordingly to key releases
*/
int	handle_key_release(int key, t_root *root)
{
	printf("key released %d\n", key);
	if (key == LEFT_KEY)
		root->control->look_left = 0;
	if (key == RIGHT_KEY)
		root->control->look_right = 0;
	if (key == W_KEY)
		root->control->move_fwd = 0;
	if (key == S_KEY)
		root->control->move_bwd = 0;
	if (key == A_KEY)
		root->control->move_left = 0;
	if (key == D_KEY)
		root->control->move_right = 0;
	if (key == UP_KEY)
		root->control->look_up = 0;
	if (key == DOWN_KEY)
		root->control->look_down = 0;
	return (0);
}