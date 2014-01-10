#include "wolf3d.h"

typedef struct 		s_cam
{
	int				pos_x;
	int				pos_y;
	int				angle;
}					t_cam;

t_cam	*new_camera(int x, int y, int angle)
{
	t_cam	cam;

	cam = (t_camera*)malloc(sizeof(t_camera));
	cam->pos_x = x;
	cam->pos_y = y;
	cam->angle = angle;
	return (cam);
}

void	set_camera(t_cam **cam, int x, int y, int angle)
{
	*(cam)->pos_x = x;
	*(cam)->pos_y = y;
	*(cam)->angle = angle;
}

void	del_camera(t_cam **cam)
{
	free(*cam);
	*cam = NULL;
}