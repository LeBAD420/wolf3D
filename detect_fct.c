#include "wolf3d.h"

static int		ft_h_intersection(int i)
{

	t_win 	*window;
	t_cam	*cam;
	t_map	*map;
	float	va;
	int		x_inc;
	int		y_inc;
	t_pos	first_inter;

	window = init_env();
	cam = ft_new_camera(NULL, 0);
	map = ft_init_map(NULL);

	va = cam->angle - M_PI / 6 + (WIN_LEN - 1 - i) * (float)FOV / WIN_LEN;
	x_inc = (int)(abs(STEP / tanf(va)));

	if (va >= 0 && va < M_PI) /* rayon vers le haut */
	{
		first_inter.y = (cam->pos->y / STEP) * STEP - 1;
		y_inc = -STEP;
	}
	else
	{
		first_inter.y = (cam->pos->y / STEP) * STEP + STEP - 1;
		y_inc = STEP;
	}
	if (va >= M_PI / 2 && va < 3 * M_PI / 2)
		x_inc = -x_inc;
	first_inter.x = cam->pos->x + (cam->pos->y - first_inter.y) / tanf(va);
	//printf("Intersection Horizontale x = %d, va = %f\n", i, va);
	//printf("valeur absolu player x= %d, y =%d\n", cam->pos->x / STEP, cam->pos->y / STEP);
	//printf("valeur pixel player x= %d, y =%d\n", cam->pos->x, cam->pos->y);
	//printf("Intersection Horizontale\n");
	//printf("Position joueur x=%d(%d), y = %d(%d), angle = %f\n",
	//	cam->pos->x, cam->pos->x / STEP, cam->pos->y, cam->pos->y / STEP, va * 180 / M_PI);
	//printf("Premiere intersection en pixel, x = %d (%d), y = %d(%d)\n"
	//	, first_inter.x, first_inter.x / STEP, first_inter.y,first_inter.y / STEP);
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

	while (map->maze[first_inter.y / STEP][first_inter.x / STEP] == PATH)
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

	/*printf("Horizontale (%d)(%f)(%d)(%d) mur trouve x= %d (%dpixel), y = %d (%dpixel)\n",i, va * 180 / M_PI, x_inc, y_inc
		, first_inter.x / STEP, first_inter.x, first_inter.y / STEP, first_inter.y);*/
	//printf("valeur absolu intersection: x=%d, y=%d\n",x / STEP, y / STEP);
	return ((int)(sqrt(powf((float)(cam->pos->x - first_inter.x), 2) + powf((float)(cam->pos->y - first_inter.y), 2))));
}

static int		ft_v_intersection(int i)
{
	float	va;
	t_win 	*window;
	t_cam	*cam;
	t_map	*map;
	int		x_inc;
	int		y_inc;
	t_pos	first_inter;

	window = init_env();
	cam = ft_new_camera(NULL, 0);
	map = ft_init_map(NULL);

	va = cam->angle - M_PI / 6 + (WIN_LEN - 1 - i) * (float)FOV / WIN_LEN;
	y_inc = (int)(abs(STEP / tanf(va)));
	if (i > 159) /* rayon a droite */
	{
		first_inter.x = (cam->pos->x / STEP) * STEP + STEP - 1;
		x_inc = STEP;
	}
	else
	{
		first_inter.x = (cam->pos->x / STEP) * STEP - 1;
		x_inc = -STEP;
	}
	first_inter.y = cam->pos->y + (cam->pos->x - first_inter.x) * tanf(va);
	if (va >= 0 && va < M_PI)
		y_inc = -y_inc;

	/*printf("Intersection Verticale\n");
	printf("Position joueur x=%d(%d), y = %d(%d), angle = %f\n",
		cam->pos->x, cam->pos->x / STEP, cam->pos->y, cam->pos->y / STEP, va * 180 / M_PI);
	printf("Premiere intersection en pixel, x = %d (%d), y = %d(%d)\n"
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
	while (map->maze[first_inter.y / STEP][first_inter.x / STEP] == PATH)
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
	/*printf("Verticale (%d)(%f)(%d)(%d) mur trouve x= %d (%dpixel), y = %d (%dpixel)\n",i, va * 180 / M_PI, x_inc, y_inc
		, first_inter.x / STEP, first_inter.x, first_inter.y / STEP, first_inter.y);*/
	return ((int)(sqrt(powf((float)(cam->pos->x - first_inter.x), 2) + powf((float)(cam->pos->y - first_inter.y), 2))));
}

static int		ft_dist_correction(int i, int dist)
{
	t_cam	*cam;
	float	va;

	cam = ft_new_camera(NULL, 0);
	va = cam->angle - M_PI / 6 + (WIN_LEN - 1 - i) * (float)FOV / WIN_LEN;
	return (dist * cosf(cam->angle - va));
	//return (dist = i < WIN_LEN / 2 - 1 ? (int)(dist * cosf(-M_PI / 6)) : (int)(dist * cosf(M_PI / 6)));
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
