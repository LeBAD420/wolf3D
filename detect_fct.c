#include "wolf3d.h"

static int is_to_far(t_pos2 *pos)
{
	t_map	*map;

	map = ft_init_map(NULL);
	if (pos->x > map->col * STEP || pos->x < 0)
		return (1);

	if (pos->y > map->row * STEP || pos->y < 0)
		return (1);
	return (0);
}

static t_wall		ft_h_intersection(int i)
{
	t_pos2	*inter;
	t_cam	*cam;
	double	va;
	t_wall	wall_null;

	cam = ft_new_camera(NULL, 0);
	wall_null.dist = 0;

	va = cam->angle - (FOV / 2) + ((WIN_WID - 1 - i) * 0.99 * FOV) / WIN_WID;
	//printf("va = %f\n", va);
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
	printf("Horizontale %f;%f (x,y) (%f,%f)->%d & va = %f et degre = %f\n", inter->x / STEP,
		inter->y / STEP, inter->x, inter->y, i, va, va * 180 / M_PI);
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
	ni->x = looking_east(va) ? oi->x + abs(STEP / tan(va)) : oi->x - abs(STEP / tan(va));
	return (ni);
}

t_wall				get_distance_h(double va, t_pos2 *inter)
{
	t_cam	*cam;
	t_wall	wall;
	int		east;

	east = looking_east(va);
	cam = ft_new_camera(NULL, 0);
	if (east == -1)
		wall.dist = HUGE;
	else
	{
		wall.dist = sqrt(pow(cam->pos->y - inter->y, 2) + pow(cam->pos->x - inter->x, 2));
		if (inter->y > cam->pos->y)
			wall.color = COLOR_WALL_NORTH;
		else
			wall.color = COLOR_WALL_SOUTH;
	}
	return (wall);
}



int					is_wall(t_pos2 *pos)
{
	t_map	*map;

	map = ft_init_map(NULL);
	if (pos->x > map->col * STEP)
	{
		printf(" ojn est trop loinnnnnnnnnnnn1\n");
		pos->x = map->col * STEP - STEP;
	}
	else if(pos->x < 0)
	{
		printf("on est nega x = %f\n", pos->x);
		//pos->x = 29;
		pos->x = 0;
	}
	if (pos->y > (map->row) * STEP)
	{
		printf(" ojn est trop loinnnnnnnnnnnn2\n");
		pos->y = (map->row) * STEP - STEP;
	}
	else if(pos->y < 0)
	{
		printf("on est nega x = %f\n", pos->x);
		pos-> y = 0;
	}
	return (map->maze[(int)pos->y / STEP][(int)pos->x / STEP] != PATH);
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

static t_wall		ft_v_intersection(int i)
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
	inter = first_v_inter(va);
    if (is_to_far(inter))
		return (wall_null);
	while(!is_wall(inter))
	{
		inter = next_v_inter(va, inter);
		if (is_to_far(inter))
			return (wall_null);
	}
	return (get_distance_v(va, inter));
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
	if (!(va == M_PI / 2 || va == 3 * M_PI / 2))
		ni->x = looking_east(va) ? oi->x + STEP : oi->x - STEP;
	else
		ni->x = oi->x;
	ni->y = looking_north(va) ? oi->y - abs(STEP * tan(va)) : oi->y + abs(STEP * tan(va));
	return (ni);
}

t_wall				get_distance_v(double va, t_pos2 *inter)
{
	t_cam	*cam;
	t_wall	wall;
	int		north;

	north = looking_north(va);
	cam = ft_new_camera(NULL, 0);
	if (north == -1)
		wall.dist = HUGE;
	else
	{
		wall.dist = sqrt(pow(cam->pos->y - inter->y , 2) + pow(cam->pos->x - inter->x, 2));
		if (inter->x > cam->pos->x)
			wall.color = COLOR_WALL_EAST;
		else
			wall.color = COLOR_WALL_WEST;
	}
	return (wall);
}

static t_wall		ft_dist_correction(int i, t_wall wall)
{
	t_cam	*cam;
	double	va;

	cam = ft_new_camera(NULL, 0);
	va = cam->angle - (FOV / 2) + ((WIN_WID - 1 - i) * 0.99 * FOV) / WIN_WID;
	wall.dist = wall.dist * cos(cam->angle - va);
	return (wall);
}

t_wall				ft_wall_distance(int i)
{
	t_wall		h_wall;
	t_wall		v_wall;
	t_cam		*cam;

	cam = ft_new_camera(NULL, 0);
	h_wall = ft_h_intersection(i);
	v_wall = ft_v_intersection(i);

	if (h_wall.dist == 0 || (v_wall.dist < h_wall.dist && v_wall.dist!= 0))
		return (ft_dist_correction(i, v_wall));
	else
		return (ft_dist_correction(i, h_wall));
}
