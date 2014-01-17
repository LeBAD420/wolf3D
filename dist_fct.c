#include "wolf3d.h"

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
		wall.dist = sqrt(pow(cam->pos->y - inter->y , 2)
							+ pow(cam->pos->x - inter->x, 2));
		if (inter->x > cam->pos->x)
			wall.color = COLOR_WALL_EAST;
		else
			wall.color = COLOR_WALL_WEST;
	}
	return (wall);
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
		wall.dist = sqrt(pow(cam->pos->y - inter->y, 2)
							+ pow(cam->pos->x - inter->x, 2));
		if (inter->y > cam->pos->y)
			wall.color = COLOR_WALL_NORTH;
		else
			wall.color = COLOR_WALL_SOUTH;
	}
	return (wall);
}

t_wall		ft_dist_correction(int i, t_wall wall)
{
	t_cam	*cam;
	double	va;

	cam = ft_new_camera(NULL, 0);
	va = cam->angle - (FOV / 2) + ((WIN_WID - 1 - i) * 0.99 * FOV) / WIN_WID;
	wall.dist = wall.dist * cos(cam->angle - va);
	return (wall);
}
