#include "./includes/wolf3d.h"

int		ft_key_hook(int keycode, t_win *window)
{
	if (keycode == KEYECHAP)
		exit(0);
	if (keycode == KEYUP)
		move_up(window);
	if (keycode == KEYDOWN)
		move_down(window);
	if (keycode == KEYLEFT)
		move_left(window);
	if (keycode == KEYRIGHT)
		move_right(window);
	return (0);
}

int		ft_expose_hook(t_win *window)
{
	/* On affiche l'img */
	mlx_put_image_to_window(window->mlx, window->win, window->img->img, 0, 0);
	return (0);
}
