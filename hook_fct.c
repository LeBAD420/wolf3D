#include "./includes/wolf3d.h"

void			ft_exit(t_win *win)
{
	if (win)
	{
		free(win->mlx);
		free(win->win);
		img_del(win->img);
		free(win);
	}
	exit(0);
}

int		ft_key_hook(int keycode, t_win *window)
{
	if (keycode == KEYECHAP)
		ft_exit(window);
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
	ft_draw(window, 500, 500);
	return (0);
}
