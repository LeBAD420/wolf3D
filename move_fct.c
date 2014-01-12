#include "./includes/wolf3d.h"

void		move_up(void)
{
	t_cam	*cam;

	cam = ft_new_camera(NULL, 0);
	rad_angle = (cam->angle * M_PI) / 180;
	cam->pos->x += cos(cam->angle) * PLAYERSTEP;
	cam->pos->y += sin(cam->angle) * PLAYERSTEP;
}

void		move_down(void)
{
	t_cam	*cam;

	cam = ft_new_camera(NULL, 0);
	cam->pos->x -= cos(cam->angle) * PLAYERSTEP;
	cam->pos->y -= sin(cam->angle) * PLAYERSTEP;
}

void		move_left(void)
{
	t_cam	*cam;

	cam = ft_new_camera(NULL, 0);
	cam->angle += PLAYERROT;
}

void		move_right(void)
{
	t_cam	*cam;

	cam = ft_new_camera(NULL, 0);
	cam->angle -= PLAYERROT;
}
