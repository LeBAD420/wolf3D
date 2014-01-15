#include "./includes/wolf3d.h"

void			ft_exit(void)
{
	env_del();
	ft_del_map();
	ft_del_camera();
	exit(0);
}

int		ft_key_hook(int keycode)
{
	t_win	*window;
	t_cam	*cam;

	window = init_env();
	cam = ft_new_camera(NULL, 0);
//	printf("Avant touche, angle=%f , x =%f, y = %f\n", cam->angle, cam->pos->x, cam->pos->y);
	if (keycode == KEYECHAP)
		ft_exit();
	if (keycode == KEYUP)
		move_up();
	if (keycode == KEYDOWN)
		move_down();
	if (keycode == KEYLEFT)
		move_left();
	if (keycode == KEYRIGHT)
		move_right();
//	printf("apres touche, angle=%f , x =%f, y = %f\n", cam->angle, cam->pos->x, cam->pos->y);
	ft_draw_img();
	mlx_put_image_to_window(window->mlx, window->win, window->img->img, 0, 0);
//	printf("apres touche, angle=%f , x =%f, y = %f\n", cam->angle * 180 / M_PI, cam->pos->x, cam->pos->y);
	return (0);
}

int		ft_expose_hook()
{
	t_win	*window;

	window = init_env();
	mlx_put_image_to_window(window->mlx, window->win, window->img->img, 0, 0);
	return (0);
}
