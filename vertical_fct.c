#include "wolf3d.h"

t_wall		ft_v_intersection(int i)
{
	t_pos2	*inter;
	t_cam	*cam;
	double	va;
	t_wall	wall_null;

	cam = ft_new_camera(NULL, 0);
	wall_null.dist = 0;
	va = cam->angle - (FOV / 2) + ((WIN_WID - 1 - i) * FOV) / WIN_WID;
	if (va < 0)
		va += 2 * M_PI;
	else if (va > 2 * M_PI)
		va -= 2 * M_PI;
	inter = first_v_inter(va);
	if (is_to_far(inter) || va == M_PI / 2 || va == 3 * M_PI / 2)
		return (wall_null);
	while (!is_wall(inter))
	{
		inter = next_v_inter(va, inter);
		if (is_to_far(inter))
			return (wall_null);
	}
	return (get_distance_v(inter));
}

t_pos2				*first_v_inter(double va)
{
	t_cam	*cam;
	t_pos2	*fi;

	fi = (t_pos2*)malloc(sizeof(t_pos2));
	cam = ft_new_camera(NULL, 0);
	fi->x = (int)(cam->pos->x / STEP) * STEP;
	fi->x = !looking_east(va) ? fi->x - 1: fi->x + STEP;
	fi->y = cam->pos->y + (cam->pos->x - fi->x) * tan(va);
	return (fi);
}

t_pos2				*next_v_inter(double va, t_pos2 *oi)
{
	t_pos2	*ni;

	ni = (t_pos2*)malloc(sizeof(t_pos2));
	ni->x = looking_east(va) ? oi->x + STEP : oi->x - STEP;
	if (looking_north(va))
		ni->y = oi->y - abs(STEP * tan(va));
	else
		ni->y = oi->y + abs(STEP * tan(va));
	ft_memdel((void **)(&oi));
	return (ni);
}
