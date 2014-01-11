#include "./includes/wolf3d.h"

int		ft_key_hook(int keycode, t_win *window)
{
	window->echap = 65307;
	if (keycode == window->echap)
	{
		if (close(window->fd) == -1)
			ft_error("close () error");
		exit(0);
	}
	return (0);
}

int		ft_expose_hook(t_win *window)
{
	window=window;
	//ft_read(window);
	//ft_draw(window, map);
	return (0);
}
