#include "./includes/wolf3d.h"

t_win			*init_env(void)
{
	t_win		*window;

	window = (t_win*)malloc(sizeof(t_win));
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, WIN_LEN, WIN_WID, "Wolf 3D");
	return (window);
}
