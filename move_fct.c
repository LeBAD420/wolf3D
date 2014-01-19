#include "./includes/wolf3d.h"

void		move_up(void)
{
	t_cam		*cam;
	t_map		*map;
	t_pos2		coord;

	cam = ft_new_camera(NULL, 0);
	map = ft_init_map(NULL);
	coord.x = cam->pos->x + cos(cam->angle) * PLAYERSTEP;
	coord.y = cam->pos->y - sin(cam->angle) * PLAYERSTEP;
	if (!is_wall(&coord))
	{
		cam->pos->x = coord.x;
		cam->pos->y = coord.y;
	}
}

void		move_down(void)
{
	t_cam		*cam;
	t_map		*map;
	t_pos2		coord;

	cam = ft_new_camera(NULL, 0);
	map = ft_init_map(NULL);
	coord.x = cam->pos->x - cos(cam->angle) * PLAYERSTEP;
	coord.y = cam->pos->y + sin(cam->angle) * PLAYERSTEP;
	if (!is_wall(&coord))
	{
			cam->pos->x = coord.x;
			cam->pos->y = coord.y;
	}
}

void		move_left(void)
{
	t_cam	*cam;

	cam = ft_new_camera(NULL, 0);
	cam->angle += PLAYERROT;
	if (cam->angle > 2 * M_PI)
		cam->angle -= 2 * M_PI;
}

void		move_right(void)
{
	t_cam	*cam;

	cam = ft_new_camera(NULL, 0);
	cam->angle -= PLAYERROT;
	if (cam->angle < 0)
		cam->angle += 2 * M_PI;
}
