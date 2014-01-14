#include "wolf3d.h"

static double		ft_h_intersection(int i)
{

	t_win 	*window;
	t_cam	*cam;
	t_map	*map;
	double	va;
	double	x_inc;
	double	y_inc;
	t_pos2	first_inter;

	window = init_env();
	cam = ft_new_camera(NULL, 0);
	map = ft_init_map(NULL);

	va = cam->angle - FOV / 2 + (WIN_LEN - 1 - i) * (double)FOV * 0.99 / WIN_LEN;
	x_inc = abs(STEP / tan(va));

	if (va >= 0 && va < M_PI) /* rayon vers le haut */
	{
		first_inter.y = (cam->pos->y / STEP) * STEP - 1;
		y_inc = -STEP;
	}
	else
	{
		first_inter.y = (cam->pos->y / STEP) * STEP + STEP;
		y_inc = STEP;
	}
	if (va >= M_PI / 2 && va < 3 * M_PI / 2)
		x_inc = -x_inc;
	first_inter.x = cam->pos->x + (cam->pos->y - first_inter.y) / tan(va);

	/*printf("Pour x = %d, Horizontale\n", i);
	printf("Position joueur x=%f(%f), y = %f(%f), angle = %f\n",
		cam->pos->x, cam->pos->x / STEP, cam->pos->y, cam->pos->y / STEP, va * 180 / M_PI);
	printf("Premiere intersection en pixel, x = %f (%f), y = %f(%f)\n"
		, first_inter.x, first_inter.x / STEP, first_inter.y,first_inter.y / STEP);*/
	//printf("Premiere intersection en absolu, x = %d, y = %d\n", first_inter.x / STEP, first_inter.y / STEP);
	//printf("Xa = %d, Ya = %d\n", x_inc, y_inc);
	if (first_inter.x > map->col * STEP - 1)
			first_inter.x = map->col * STEP - 1;
		if (first_inter.x < 0)
			first_inter.x = 0;

		if (first_inter.y > (map->row - 1) * STEP - 1)
			first_inter.y = (map->row - 1) * STEP - 1;
		if (first_inter.y < 0)
			first_inter.y = 0;

	while (map->maze[(int)(first_inter.y / STEP)][(int)(first_inter.x / STEP)] == PATH)
	{
		first_inter.y += y_inc;
		first_inter.x += x_inc;

		/* Si on depasse la map */
		if (first_inter.x > map->col * STEP - 1)
			first_inter.x = map->col * STEP - 1;
		if (first_inter.x < 0)
			first_inter.x = 0;

		if (first_inter.y > (map->row - 1) * STEP - 1)
			first_inter.y = (map->row - 1) * STEP - 1;
		if (first_inter.y < 0)
			first_inter.y = 0;


	}

	//printf("Horizontale (%d)(%f)(%f)(%f) mur trouve x= %f (%fpixel), y = %f (%fpixel)\n",i, va * 180 / M_PI, x_inc, y_inc
		//, first_inter.x / STEP, first_inter.x, first_inter.y / STEP, first_inter.y);
	//printf("valeur absolu intersection: x=%d, y=%d\n",x / STEP, y / STEP);
	return ((sqrt(pow((cam->pos->x - first_inter.x), 2) + pow((cam->pos->y - first_inter.y), 2))));
}

static double		ft_v_intersection(int i)
{
	double	va;
	t_win 	*window;
	t_cam	*cam;
	t_map	*map;
	double	x_inc;
	double	y_inc;
	t_pos2	first_inter;

	window = init_env();
	cam = ft_new_camera(NULL, 0);
	map = ft_init_map(NULL);

	va = cam->angle - FOV / 2 + (WIN_LEN - 1 - i) * FOV * 0.99 / WIN_LEN;
	y_inc = abs(STEP / tan(va));
	if (va >= M_PI / 2 && va < 3 * M_PI / 2) /* rayon a droite */
	{
		first_inter.x = (cam->pos->x / STEP) * STEP + STEP;
		x_inc = STEP;
	}
	else
	{
		first_inter.x = (cam->pos->x / STEP) * STEP - 1;
		x_inc = -STEP;
	}
	first_inter.y = cam->pos->y + (cam->pos->x - first_inter.x) * tan(va);
	if (va >= 0 && va < M_PI)
		y_inc = -y_inc;

	/*printf("Intersection Verticale\n");
	printf("Position joueur x=%f(%f), y = %f(%f), angle = %f\n",
		cam->pos->x, cam->pos->x / STEP, cam->pos->y, cam->pos->y / STEP, va * 180 / M_PI);
	printf("Premiere intersection en pixel, x = %f (%f), y = %f(%f)\n"
		, first_inter.x, first_inter.x / STEP, first_inter.y,first_inter.y / STEP);*/
	//printf("Intersection Verticale x = %d, va =%f\n", i, va);
	//printf("valeur absolu player x= %d, y =%d\n", cam->pos->x / STEP, cam->pos->y / STEP);
	//printf("valeur pixel player x= %d, y =%d\n", cam->pos->x, cam->pos->y);
	//printf("Premiere intersection en pixel, x = %d, y = %d\n", first_inter.x, first_inter.y);
	//printf("Premiere intersection en absolu, x = %d, y = %d\n", first_inter.x / STEP, first_inter.y / STEP);
	//printf("Xa = %d, Ya = %d\n", x_inc, y_inc);
	if (first_inter.x > map->col * STEP - 1)
			first_inter.x = map->col * STEP - 1;
		if (first_inter.x < 0)
			first_inter.x = 0;

		if (first_inter.y > (map->row - 1) * STEP - 1)
			first_inter.y = (map->row - 1) * STEP - 1;
		if (first_inter.y < 0)
			first_inter.y = 0;
	while (map->maze[(int)(first_inter.y / STEP)][(int)(first_inter.x / STEP)] == PATH)
	{
		first_inter.y += y_inc;
		first_inter.x += x_inc;

		/*printf("Verticale new cooortrouve x = %d(%d), y = %d(%d)\n"
			, first_inter.x, first_inter.x / STEP, first_inter.y, first_inter.y / STEP);*/

		/* Si on depasse la map */
		if (first_inter.x > map->col * STEP - 1)
			first_inter.x = map->col * STEP - 1;
		if (first_inter.x < 0)
			first_inter.x = 0;

		if (first_inter.y > (map->row - 1) * STEP - 1)
			first_inter.y = (map->row - 1) * STEP - 1;
		if (first_inter.y < 0)
			first_inter.y = 0;
	}
/*	printf("Verticale (%d)(%f)(%f)(%f) mur trouve x= %f (%fpixel), y = %f (%fpixel)\n",i, va * 180 / M_PI, x_inc, y_inc
		, first_inter.x / STEP, first_inter.x, first_inter.y / STEP, first_inter.y);*/
	return ((sqrt(pow((cam->pos->x - first_inter.x), 2) + pow((cam->pos->y - first_inter.y), 2))));
}

static double		ft_dist_correction(int i, double dist)
{
	t_cam	*cam;
	double	va;

	cam = ft_new_camera(NULL, 0);
	va = cam->angle - FOV / 2 + (WIN_LEN - 1 - i) * 0.99 * FOV / WIN_LEN;
	return (dist * cos(va - cam->angle));
	//return (dist = i < WIN_LEN / 2 - 1 ? (int)(dist * cosf(-M_PI / 6)) : (int)(dist * cosf(M_PI / 6)));
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
