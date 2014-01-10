#include "./includes/wolf3d.h"



int		main(int argc, char **argv)
{
	t_win	window;

	//Check argv
	if (argc > 2)
		ft_error("Too many parameters in command line");

	//Check map et Init Map
	if ((window.fd = open(argv[1], O_RDONLY)) == -1)
		ft_error("open () error");

	//Init Env
	window.mlx = mlx.init();
	window.win = mlx_new_window(window.mlx, WIN_LEN, WIN_WID, "wolf3d");
	/*mlx_key_hook(window.win, ft_key_hook, &window);
	mlx_expose_hook(window.win, ft_expose_hook, &window);
	mlx_loop(window.mlx);*/

	//Init camera

	//Calcul Img

	//Draw Img

	//Loop

	//Fini !
	if (close(window.fd) == -1)
		ft_error("close () error");
	return (0);
}
