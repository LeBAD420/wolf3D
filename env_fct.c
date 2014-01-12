#include "./includes/wolf3d.h"

t_win			*init_env(void)
{
	static t_win		*window = NULL;

	if (window == NULL)
	{
		window = (t_win*)malloc(sizeof(t_win));
		window->mlx = mlx_init();
		window->win = mlx_new_window(window->mlx, WIN_LEN, WIN_WID, "Wolf 3D");
		window->img = init_img(window);
	}
	return (window);
}

void			env_del(t_win *win)
{
	if (win)
	{
		free(win->mlx);
		free(win->win);
		img_del(win->img);
		free(win);
	}
}