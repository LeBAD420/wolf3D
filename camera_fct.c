#include "./includes/wolf3d.h"

t_cam			*ft_new_camera(t_pos2 *pos, double angle)
{
	static t_cam	*cam = NULL;

	if (cam == NULL)
	{
		cam = (t_cam*)malloc(sizeof(t_cam));
		cam->pos = pos_init(pos->x, pos->y);
		cam->angle = angle;
	}
	return (cam);
}

void			ft_del_camera(void)
{
	t_cam *cam;

	cam = ft_new_camera(NULL, 0);
	pos_del(cam->pos);
	free(cam);
	cam = NULL;
}
