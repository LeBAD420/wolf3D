#include "./includes/wolf3d.h"

int		main(int argc, char **argv)
{
	t_win	*window;
	t_cam	*cam;
	t_map	*map;

	/* Check argv */
	if (argc > 2 || argc == 1)
		ft_error("Too or not enough parameters in command line");

	/* Init Map */
	map = ft_init_map(argv[1]);

	/* Init Env */
	window = init_env();
	mlx_key_hook(window->win, ft_key_hook, window);
	mlx_expose_hook(window->win, ft_expose_hook, window);
	mlx_loop(window->mlx);

	/* Init Camera */
	cam = ft_new_camera(map->start, STARTANGLE);

	/* Init img */
	window->img = init_img(window);

	/* Display view */
	display_view(window, map, cam);

	/* Fini ! */
	return (0);
}
