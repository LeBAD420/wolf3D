#include "./includes/wolf3d.h"

t_cam	*ft_new_camera(int x, int y, int angle)
{
	t_cam	*cam;

	cam = (t_cam*)malloc(sizeof(t_cam));
	cam->pos_x = x;
	cam->pos_y = y;
	cam->angle = angle;
	return (cam);
}

void	ft_set_camera(t_cam *cam, int x, int y, int angle)
{
	cam->pos_x = x;
	cam->pos_y = y;
	cam->angle = angle;
}

void	ft_del_camera(t_cam *cam)
{
	free(cam);
	cam = NULL;
}
