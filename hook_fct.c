#include "./includes/wolf3d.h"

int		ft_key_hook(int keycode, t_win *window)
{

	keycode++;
	window=window;
	return (0);
}

int		ft_expose_hook(t_win *window)
{
	window=window;
	return (0);
}
