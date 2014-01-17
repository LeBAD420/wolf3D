#include "wolf3d.h"

t_wall		ft_h_intersection(int i)
{
	t_pos2	*inter;
	t_cam	*cam;
	double	va;
	t_wall	wall_null;

	cam = ft_new_camera(NULL, 0);
	wall_null.dist = 0;
	va = cam->angle - (FOV / 2) + ((WIN_WID - 1 - i) * 0.99 * FOV) / WIN_WID;
	if (va < 0)
		va += 2 * M_PI;
	else if (va > 2 * M_PI)
		va -= 2 * M_PI;
	inter = first_h_inter(va);
	if (is_to_far(inter))
		return (wall_null);
	while(!is_wall(inter))
	{
		inter = next_h_inter(va, inter);
		if (is_to_far(inter))
			return (wall_null);
	}
	return (get_distance_h(va, inter));
}

t_pos2				*first_h_inter(double va)
{
	t_cam	*cam;
	t_pos2	*fi;

	cam = ft_new_camera(NULL, 0);
	fi = (t_pos2*)malloc(sizeof(t_pos2));
	fi->y = (int)(cam->pos->y / STEP) * STEP;
	fi->y = looking_north(va) ? fi->y - 1: fi->y + STEP;
	fi->x = cam->pos->x + (cam->pos->y - fi->y) / tan(va);
	return (fi);
}

t_pos2				*next_h_inter(double va, t_pos2 *oi)
{
	t_pos2	*ni;

	ni = (t_pos2*)malloc(sizeof(t_pos2));
	if (!(va == 0 || va == M_PI))
		ni->y = looking_north(va) ? oi->y - STEP : oi->y + STEP;
	else
		ni->y = oi->y;
	if (looking_east(va))
		ni->x = oi->x + abs(STEP / tan(va));
	else
		ni->x = oi->x - abs(STEP / tan(va));
	return (ni);
}
