#include "wolf3d.h"

static int		ft_h_intersection(int i, int m)
{
	t_map	*map;
	t_cam	*cam;
	t_pos	*pos;
	t_pos	*inc;
	float	va;

	map = ft_init_map(NULL);
	cam = ft_new_camera(NULL, 0);
	va = cam->angle + i * (float)FOV / WIN_LEN;
	inc = pos_init((int)STEP / tanf(va), STEP);
	pos = pos_init(0, 0);
	if (va >= 0 && va < 180)
		pos->y = (cam->pos->y / STEP) * STEP - 1 - m * STEP;
	else if (va >= 180 && va < 360)
		pos->y = (cam->pos->y / STEP) * STEP + STEP - 1 + m * STEP;
	pos->x = cam->pos->x + (int)((cam->pos->y - pos->y) / tanf(va)) + m * STEP;
	if (map->maze[pos->y / STEP][pos->x / STEP] == PATH)
		ft_h_intersection(i, m + 1);
	return ((int)(abs(cam->pos->x - pos->x) / cosf(va)));
}

static int		ft_v_intersection(int i, int m)
{
	t_pos	*pos;
	t_pos	*inc;
	float	va;
	t_map	*map;
	t_cam	*cam;

	map = ft_init_map(NULL);
	cam = ft_new_camera(NULL, 0);
	va = cam->angle + i * (float)FOV / WIN_LEN;
	pos = pos_init(0, 0);
	inc = pos_init(STEP, (int)(STEP / tanf(va)));
	if ((va >= 270 && va < 360) || (va >= 0 && va < 90))
		pos->x = (cam->pos->x / STEP) * STEP + STEP - 1 + m * inc->x;
	else if ((va >= 90 && va < 180) || (va >= 180 && va < 270))
		pos->x = (cam->pos->x / STEP) * STEP - 1 - m * inc->x;
	pos->y = cam->pos->y + (int)
		((cam->pos->x - pos->x) / tanf(va)) + m * inc->x;
	if (map->maze[pos->y / STEP][pos->x / STEP] == PATH)
		ft_v_intersection(i, m + 1);
	return ((int)(abs(cam->pos->x - pos->x) / cosf(va)));
}

static int		ft_dist_correction(int i, int dist)
{
	return (dist = i < 160 ? (int)(dist * cosf(30)) : (int)(dist * cosf(-30)));
}

int				ft_wall_distance(int i)
{
	int		h_dist;
	int		v_dist;
	t_map	*map;
	t_cam	*cam;

	map = ft_init_map(NULL);
	cam = ft_new_camera(NULL, 0);

	h_dist = ft_h_intersection(i, 0);
	v_dist = ft_v_intersection(i, 0);
	if (h_dist <= v_dist)
		return (h_dist = ft_dist_correction(i, h_dist));
	else
		return (v_dist = ft_dist_correction(i, v_dist));
}
