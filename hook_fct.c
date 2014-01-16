#include "./includes/wolf3d.h"

int		ft_expose_hook(t_win	*window)
{
	mlx_put_image_to_window(window->mlx, window->win, window->img->img, 0, 0);
	return (0);
}

int 	ft_keypress(int keycode, t_win *window)
{
	if (keycode == KEYECHAP)
		exit(0);
	if (keycode ==  KEYUP)
		window->save[0] = 1;
	if (keycode == KEYDOWN)
		window->save[1] = 1;
	if (keycode == KEYLEFT)
		window->save[2] = 1;
	if (keycode == KEYRIGHT)
		window->save[3] = 1;
	return (0);
}

int 	ft_key_release(int keycode, t_win *window)
{
	if (keycode == KEYUP)
		window->save[0] = 0;
	if (keycode == KEYDOWN)
		window->save[1] = 0;
	if (keycode == KEYLEFT)
		window->save[2] = 0;
	if (keycode == KEYRIGHT)
		window->save[3] = 0;
	return (0);
}

int 	ft_loop_hook(t_win *window)
{
	int 	i;
	int 	ok;

	i = -1;
	ok = 0;
	while (++i != 4)
	{
		if (window->save[i])
			ok = 1;
	}
	if (ok == 0)
		return (0);
	if (window->save[0])
		move_up();
	if (window->save[1])
		move_down();
	if (window->save[2])
		move_left();
	if (window->save[3])
		move_right();
	ft_draw_img();
	mlx_put_image_to_window(window->mlx, window->win, window->img->img, 0, 0);
	return (0);
}

void			ft_exit(void)
{
	env_del();
	ft_del_map();
	ft_del_camera();
	exit(0);
}
