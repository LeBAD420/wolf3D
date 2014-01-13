#include "./includes/wolf3d.h"

t_pos			*pos_init(int x, int y)
{
	t_pos	*new_pos;

	new_pos = (t_pos *)malloc(sizeof(t_pos));
	new_pos->x = x;
	new_pos->y = y;
	return (new_pos);
}

void			pos_del(t_pos *pos)
{
	free(pos);
	pos = NULL;
}