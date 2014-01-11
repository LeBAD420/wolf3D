#include "./includes/wolf3d.h"

t_img	*init_img(t_win *win)
{
	t_img	*img;

	img = (t_img*)malloc(sizeof(t_img));
	img->img = mlx_new_image(win->mlx, WIN_WID, WIN_LEN);
	img->data = mlx_get_data_addr(img->img, &img->bbp,
		&img->size_line, &img->endian);
	return (img);
}
