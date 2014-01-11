#include "wolf3d.h"

static int		ft_h_intersection(int i, int mult, t_cam *cam, t_map *map)
{
	int		x;
	int		y;
	int		x_inc;
	int		y_inc;
	float	va;

	va = cam->angle + i * (float)FOV / WIN_LEN;
	x_inc = (int)(STEP / tanf(va));
	y_inc = STEP;
	if (va >= 0 && va < 180)
		y = (cam->pos_y / STEP) * STEP - 1 - mult * STEP;
	else if (va >= 180 && va < 360)
		y = (cam->pos_y / STEP) * STEP + STEP - 1 + mult * STEP;
	x = cam->pos_x + (int)((cam->pos_y - y) / tanf(va)) + mult * STEP;
	if (map->lines[y / STEP][x / STEP] == PATH)
		ft_h_intersection(i, mult + 1, cam, map);
	return ((int)(abs(cam->pos_x - x) / cosf(va)))
}

static int		ft_v_intersection(int i, int mult, t_cam cam, t_map *map)
{
	int		x;
	int		y;
	int		x_inc;
	int		y_inc;
	float	va;

	va = cam->angle + i * (float)FOV / WIN_LEN;
	x_inc = STEP;
	y_inc = (int)(STEP / tanf(va));
	if ((va >= 270 && va < 360) || (va >= 0 && va < 90))
		x = (cam->pos_x / STEP) * STEP + STEP - 1 + mult * x_inc;
	else if ((va >= 90 && va < 180) || (va >= 180 && va < 270))
		x = (cam->pos_x / STEP) * STEP - 1 - mult * x_inc;
	y = cam->pos_y + (int)((cam.pos_x - x) / tanf(va)) + mult * y_inc;
	if (map->lines[y / STEP][x / STEP] == PATH)
		ft_v_intersection(i, mult + 1, cam, map);
	return (int(abs(cam->pos_x - x) / cosf(va)));
}

static int		ft_dist_corretion(int i, int dist)
{
	return (dist = i < 159 ? (int)(dist * cosf(30)) : (int)(dist * cosf(-30)));
}

static int		ft_wall_distance(int i, t_cam *cam, t_map *map)
{
	int		h_dist;
	int		v_dist;

	h_dist = ft_h_intersection(i, 0, cam, map);
	v_dist = ft_v_intersection(i, 0, cam, map);
	if (h_dist <= v_dist)
		return (h_dist = ft_dist_correction(i, h_dist));
	else
		return (v_dist = ft_dist_correction(i, v_dist));
}

void	ft_detect_wall(t_win window, t_cam *cam, t_map *map)
{
	int		i;
	int		wall_dist;

	i = 0;
	while (i < WIN_LEN)
	{
		wall_dist = ft_wall_distance(i, cam, map);
		ft_draw(window, wall_dist, WIN_LEN - i);
	}
}
