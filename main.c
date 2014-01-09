#include <fcntl.h>
#include "wolf3d.h"

static int		ft_key_hook(int keycode, t_win *window)
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

static int		ft_expose_hook(t_win *window)
{
	ft_read(window);
	ft_draw(window, map);
	return (0);
}

int		main(int argc, char **argv)
{
	t_win	window;

	if (argc > 2)
		ft_error("Too many parameters in command line");
	if ((window.fd = open(argv[1], O_RDONLY)) == -1)
		ft_error("open () error");
	window.mlx = mlx.init();
	window.win = mlx_new_window(window.mlx, WIN_LEN, WIN_WID, "wolf3d");
	mlx_key_hook(window.win, ft_key_hook, &window);
	mlx_expose_hook(window.win, ft_expose_hook, &window);
	mlx_loop(window.mlx);
	if (close(window.fd) == -1)
		ft_error("close () error");
	return (0);
}
