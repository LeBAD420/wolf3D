#include "wolf3d.h"

int		is_to_far(t_pos2 *pos)
{
	t_map	*map;

	map = ft_init_map(NULL);
	if (pos->x > map->col * STEP || pos->x < 0)
		return (1);
	if (pos->y > map->row * STEP || pos->y < 0)
		return (1);
	return (0);
}

int		is_wall(t_pos2 *pos)
{
	t_map	*map;

	map = ft_init_map(NULL);
	if (pos->x > map->col * STEP)
		pos->x = map->col * STEP - STEP;
	else if(pos->x < 0)
		pos->x = 0;
	if (pos->y > (map->row) * STEP)
		pos->y = (map->row) * STEP - STEP;
	else if(pos->y < 0)
		pos-> y = 0;
	return (map->maze[(int)pos->y / STEP][(int)pos->x / STEP] != PATH);
}

int		looking_north(double va)
{
	if (va == 0 || va == M_PI)
		return (-1);
	else
		return (va > 0 && va < M_PI);
}

int		looking_east(double va)
{
	if (va == M_PI / 2 || va == 3 * M_PI / 2)
		return (-1);
	else
		return (va < M_PI / 2 || va > 3 * M_PI / 2);
}
