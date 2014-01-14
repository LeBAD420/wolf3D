#include "wolf3d.h"

static int		ft_h_intersection(int i)
{

	t_win 	*window;
	t_cam	*cam;
	t_map	*map;
	float	va;
	int		x;
	int		y;
	int		x_inc;
	int		y_inc;
	int		mult;
	t_pos	first_inter;

	mult = 0;
	window = init_env();
	cam = ft_new_camera(NULL, 0);
	map = ft_init_map(NULL);
	x = cam->pos->x;
	y = cam->pos->y;
	va = cam->angle - M_PI / 6 + i * (float)FOV / WIN_LEN;
	x_inc = (int)(abs(STEP / tanf(va)));
	y_inc = STEP;
	if (va >= 0 && va < M_PI) /* rayon vers le haut */
		first_inter.y = (cam->pos->y / STEP) * STEP - 1;
	else
		first_inter.y = (cam->pos->y / STEP) * STEP + STEP;
	first_inter.x = cam->pos->x + (cam->pos->y - first_inter.y) / tanf(va);
	printf("valeur absolu player x= %d, y =%d\n", cam->pos->x / STEP, cam->pos->y / STEP);
	printf("valeur pixel player x= %d, y =%d\n", cam->pos->x, cam->pos->y);
	printf("Premiere intersection en pixel, x = %d, y = %d\n", first_inter.x, first_inter.y);
	printf("Premiere intersection en absolu, x = %d, y = %d\n", first_inter.x / STEP, first_inter.y / STEP);

	while (map->maze[first_inter.y / STEP][first_inter.x / STEP] == PATH)
	{
		first_inter.y += y_inc;
		first_inter.x += x_inc;
		/*if (va >= 0 && va < M_PI)
			y = (cam->pos->y / STEP) * STEP - 1 - mult * STEP;
		else if (va >= M_PI && va < 2 * M_PI)
			y = (cam->pos->y / STEP) * STEP + STEP - 1 + mult * STEP;
		if ((va >= 3 * M_PI / 2 && va < 2 * M_PI) || (va >= 0 && va < M_PI / 2))
            x = cam->pos->x + (int)((cam->pos->y - y) / tanf(va)) + mult * x_inc;
        else if ((va >= M_PI / 2 && va < 3 * M_PI / 2))
			x = cam->pos->x + (int)((cam->pos->y - y) / tanf(va)) - mult * x_inc;
		//printf("valeur intersection x= %d, y=%d\n", x, y);
		mult++;
		if (x < 0)
            x = 0;
        if (y < 0)
			y = 0;
		if (x > map->col * STEP - 1)
		{
            x = map->col * STEP - 1;
            printf("max2 atteint\n");
		}
        if (y > (map->row - 1) * STEP - 1)
        {
            y = (map->row - 1) * STEP - 1;
            printf("max atteint\n");
        }
        //printf("valeur intersection x= %d, y=%d\n", x, y);
        //printf("valeur de la case =%c\n", map->maze[y / STEP][x / STEP]);*/
	}
	printf("mur trouve x= %d, y = %d\n", first_inter.x / STEP, first_inter.y / STEP);
	//printf("valeur absolu intersection: x=%d, y=%d\n",x / STEP, y / STEP);
	return ((int)(sqrt(powf((float)(cam->pos->x - x), 2) + powf((float)(cam->pos->y - y), 2))));
}

static int		ft_v_intersection(int i)
{
	float	va;
	t_win 	*window;
	t_cam	*cam;
	t_map	*map;
	int		x;
	int		y;
	int		x_inc;
	int		y_inc;
	int		mult;

	mult = 0;
	window = init_env();
	cam = ft_new_camera(NULL, 0);
	map = ft_init_map(NULL);
	x = cam->pos->x;
	y = cam->pos->y;
	va = cam->angle - M_PI / 6 + i * (float)FOV / WIN_LEN;
	x_inc = STEP;
	y_inc = (int)(abs(STEP / tanf(va)));

	while (map->maze[y / STEP][x / STEP] == PATH)
	{
		if ((va >= 3 * M_PI / 2 && va < 2 * M_PI) || (va >= 0 && va < M_PI / 2))
			x = (cam->pos->x / STEP) * STEP + STEP - 1 + mult * x_inc;
		else if ((va >= M_PI / 2 && va < 3 * M_PI / 2))
			x = (cam->pos->x / STEP) * STEP - 1 - mult * x_inc;
		if (va >= 0 && va < M_PI)
            y = cam->pos->y + (int)((cam->pos->x - x) / tanf(va)) - mult * y_inc;
        else if (va >= M_PI && va < 2 * M_PI)
			y = cam->pos->y + (int)((cam->pos->x - x) / tanf(va)) + mult * y_inc;
		mult++;
		if (x < 0)
			x = 0;
		if (y < 0)
			y = 0;
		if (x > map->col * STEP - 1)
			x = map->col * STEP - 1;
		if (y > (map->row - 1) * STEP - 1)
			y = (map->row - 1) * STEP - 1;
	}
	return ((int)(sqrt(powf((float)(cam->pos->x - x), 2) + powf((float)(cam->pos->y - y), 2))));
}

static int		ft_dist_correction(int i, int dist)
{
	return (dist = i < WIN_LEN - 1 ? (int)(dist * cosf(-M_PI / 6)) : (int)(dist * cosf(M_PI / 6)));
}

int				ft_wall_distance(int i)
{
	int		h_dist;
	int		v_dist;

	h_dist = ft_h_intersection(i);
	v_dist = ft_v_intersection(i);
	if (h_dist <= v_dist)
		return (ft_dist_correction(i, h_dist));
	else
		return (ft_dist_correction(i, v_dist));
}
