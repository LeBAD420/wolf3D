#include "wolf3d.h"


static int		ft_h_intersection(int i, int mult, t_win *window)
{
	t_map	*map;
	t_cam	*cam;
	t_pos	*pos;
	t_pos	*inc;
	float	va;

	x = window->cam->pos_x;
	y = window->cam->pos_y;
	va = window->cam->angle - PI / 6 + i * (float)FOV / WIN_LEN;
	x_inc = (int)(STEP / tanf(va));
	y_inc = STEP;
	while (window->map->lines[y / STEP][x / STEP] == PATH)
	{
		if (va >= 0 && va < PI)
			y = (window->cam->pos_y / STEP) * STEP - 1 - mult * STEP;
		else if (va >= PI && va < 2 * PI)
			y = (window->cam->pos_y / STEP) * STEP + STEP - 1 + mult * STEP;
		if ((va >= 3 * PI / 2 && va < 2 * PI) || (va >= 0 && va < PI / 2))
            x = window->cam->pos_x + (int)((window->cam->pos_y - y) / tanf(va)) + mult * x_inc;
        else if ((va >= PI / 2 && va < 3 * PI / 2))
			x = window->cam->pos_x + (int)((window->cam->pos_y - y) / tanf(va)) - mult * x_inc;
		mult++;
	}
	return ((int)(abs((window->cam->pos_x - x) / cosf(va))));
}

static int		ft_v_intersection(int i, int mult, t_win *window)
{
	t_pos	*pos;
	t_pos	*inc;
	float	va;
	t_map	*map;
	t_cam	*cam;

	x = window->cam->pos_x;
	y = window->cam->pos_y;
	va = window->cam->angle - PI / 6 + i * (float)FOV / WIN_LEN;
	x_inc = STEP;
	y_inc = (int)(STEP / tanf(va));
	while (window->map->lines[y / STEP][x / STEP] == PATH)
	{
		if ((va >= 3 * PI / 2 && va < 2 * PI) || (va >= 0 && va < PI / 2))
			x = (window->cam->pos_x / STEP) * STEP + STEP - 1 + mult * x_inc;
		else if ((va >= PI / 2 && va < 3 * PI / 2))
			x = (window->cam->pos_x / STEP) * STEP - 1 - mult * x_inc;
		if (va >= 0 && va < PI)
            y = window->cam->pos_y + (int)((window->cam->pos_x - x) / tanf(va)) - mult * y_inc;
        else if (va >= PI && va < 2 * PI)
			y = window->cam->pos_y + (int)((window->cam->pos_x - x) / tanf(va)) + mult * y_inc;
		mult++;
	}
	return ((int)(abs((window->cam->pos_x - x) / cosf(va))));
}

static int		ft_dist_correction(int i, int dist)
{
	return (dist = i < WIN_LEN - 1 ? (int)(dist * cosf(-PI / 6)) : (int)(dist * cosf(PI / 6)));
}

int				ft_wall_distance(int i)
{
	int		h_dist;
	int		v_dist;

	h_dist = ft_h_intersection(i, 0, window);
	printf("h_dist = %d\n", h_dist);
	v_dist = ft_v_intersection(i, 0, window);
	printf("v_dist = %d\n", v_dist);
	h_dist = ft_h_intersection(i, 0);
	v_dist = ft_v_intersection(i, 0);
	if (h_dist <= v_dist)
		return (h_dist = ft_dist_correction(i, h_dist));
	else
		return (v_dist = ft_dist_correction(i, v_dist));
}

void	ft_detect_wall(t_win *window)
{
	int		i;
	int		wall_dist;

	i = 0;
	while (i < WIN_LEN)
	{
		wall_dist = ft_wall_distance(i, window);
		ft_draw(window, wall_dist, WIN_LEN - i);
		i++;
	}
}

