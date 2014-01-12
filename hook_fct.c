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
	//ft_draw_img();
	return (0);
}

int		ft_expose_hook()
{
	t_win	*window;

	window = init_env();
	mlx_put_image_to_window(window->mlx, window->win, window->img->img, 0, 0);
	return (0);
}
