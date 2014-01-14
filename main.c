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
	/* Init Camera */
	cam = ft_new_camera(map->start, M_PI / 2);

	/* Init img */
	window->img = init_img();

	mlx_do_key_autorepeaton(window->mlx);
	mlx_hook(window->win, 2, (1L << 0), ft_key_hook, window);
	mlx_expose_hook(window->win, ft_expose_hook, window);
	ft_draw_img();
	mlx_put_image_to_window(window->mlx, window->win, window->img->img, 0, 0);
	mlx_loop(window->mlx);


	/* Display view */
	/* Fini ! */
	return (0);
}
