#include "wolf3d.h"

static double		ft_h_intersection(int i)
{
	t_pos	*inter;
	t_cam	*cam;
	double	va;
	int		x_iter;

	cam = ft_new_camera(NULL, 0);
	va = cam->angle - (FOV / 2) + ((WIN_WID - 1 - i) * FOV) / WIN_WID;
	inter = first_h_inter(va);
	while(!is_wall(inter))
		inter = next_h_inter(va, inter);
	return (abs(cam->pos->y - inter->y) * sin(va));
}

t_pos				*first_h_inter(double va)
{
	t_cam	*cam;
	t_pos	*fi;

	cam = ft_new_camera(NULL, 0);
	fi->y = (int)(cam->pos->y / STEP) * STEP;
	fi->y = looking_north(va) ? fi->y - 1 : fi->y + STEP;
	fi->x = cam->pos->x + (cam->pos->y - inter->y) / tan(va);
	return (fi);
}

t_pos				*next_h_inter(double va, t_pos *oi)
{
	t_pos	*ni;

	ni->y = looking_north(va) ? oi->y + STEP : oi->y - STEP;
	ni->x = looking(east) ? abs(STEP / tan(va)) : -abs(STEP / tan(va));
	return (ni);
}

is_wall(t_pos *pos)
{
	t_map	*map;

	map = ft_init_map(NULL);
	if (pos->x > map->col * STEP)
		pos->x = mmap->col * STEP - STEP;
	else if(pos->x < 0)
		pos->x = 0;
	if (pos->y > map->row * STEP)
		pos->y = map->row * STEP - STEP;
	else if(pos->y < 0)
		pos-> y = 0;
	return (map->maze[pos->x / STEP][pos->y / STEP] == PATH)
}

int					looking_north(double va)
{
	if (va == 0 || va == M_PI)
		return (-1);
	else
		return (va > 0 && va < M_PI);
}

int					looking_east(double va)
{
	if (va == M_PI / 2 || va == 3 * M_PI / 2)
		return (-1);
	else
		return (va < M_PI / 2 || va > 3 * M_PI / 2);
}

////////////

static double		ft_v_intersection(int i)
{
}

static double		ft_dist_correction(int i, double dist)
{
	t_cam	*cam;
	double	va;

	cam = ft_new_camera(NULL, 0);
	va = cam->angle - FOV / 2 + (WIN_WID - 1 - i) * 0.99 * FOV / WIN_WID;
	return (dist * cos(va - cam->angle));
}

double				ft_wall_distance(int i)
{
	double		h_dist;
	double		v_dist;

	h_dist = ft_h_intersection(i);
	v_dist = ft_v_intersection(i);
	if (h_dist <= v_dist)
		return (ft_dist_correction(i, h_dist));
	else
		return (ft_dist_correction(i, v_dist));
}
