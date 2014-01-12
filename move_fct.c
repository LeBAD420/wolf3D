#include "./includes/wolf3d.h"

void		move_up(t_win *win)
{
	t_cam	*cam;
	float	rad_angle;

	cam = ft_new_camera(NULL, 0);
	rad_angle = (cam->angle * M_PI) / 180;
	cam->pos->x += cos(rad_angle) * PLAYERSTEP;
	cam->pos->y += sin(rad_angle) * PLAYERSTEP;
	win = win;
}

void		move_down(t_win *win)
{
	t_cam	*cam;
	float	rad_angle;

	cam = ft_new_camera(NULL, 0);
	cam->pos->x -= cos(rad_angle) * PLAYERSTEP;
	cam->pos->y -= sin(rad_angle) * PLAYERSTEP;
	win=win;
}

void		move_left(t_win *win)
{
	t_cam	*cam;

	cam = ft_new_camera(NULL, 0);
	cam->angle += PLAYERROT;
	win=win;
}

void		move_right(t_win *win)
{
	t_cam	*cam;

	cam = ft_new_camera(NULL, 0);
	cam->angle -= PLAYERROT;
	win=win;
}
