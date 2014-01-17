#include "./includes/wolf3d.h"

int		main(int argc, char **argv)
{
	t_win	*window;
	t_cam	*cam;
	t_map	*map;

	if (argc > 2 || argc == 1)
		ft_error("Too or not enough parameters in command line");
	map = ft_init_map(argv[1]);
	window = init_env();
	cam = ft_new_camera(map->start, STARTANGLE);
	window->img = init_img();
	mlx_hook(window->win, 2, 1, ft_keypress, window);
	mlx_hook(window->win, 3, 2, ft_key_release, window);
	mlx_loop_hook(window->mlx, ft_loop_hook, window);
	mlx_expose_hook(window->win, ft_expose_hook, window);
	ft_draw_img();
	mlx_put_image_to_window(window->mlx, window->win, window->img->img, 0, 0);
	mlx_loop(window->mlx);
	return (0);
}
