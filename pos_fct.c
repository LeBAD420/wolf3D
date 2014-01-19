#include "./includes/wolf3d.h"

t_pos2		*pos_init(double x, double y)
{
	t_pos2	*new_pos;

	new_pos = (t_pos2 *)malloc(sizeof(t_pos2));
	new_pos->x = x;
	new_pos->y = y;
	return (new_pos);
}

void		pos_del(t_pos2 *pos)
{
	free(pos);
	pos = NULL;
}
