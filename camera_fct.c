#include "./includes/wolf3d.h"

t_cam			*ft_new_camera(t_pos *pos, int angle)
{
	t_cam	*cam;

	cam = (t_cam*)malloc(sizeof(t_cam));
	cam->pos = pos_init(pos->x, pos->y);
	cam->angle = angle;
	return (cam);
}

void			ft_set_camera(t_cam *cam, t_pos *pos, int angle)
{
	cam->pos->x = pos->x;
	cam->pos->y = pos->y;
	cam->angle = angle;
}

void			ft_del_camera(t_cam *cam)
{
	pos_del(cam->pos);
	free(cam);
	cam = NULL;
}
