#include "./includes/wolf3d.h"

void		move_up(t_win *win)
{
	t_map	*map;

	win=win;
	map = ft_init_map(NULL);
}

void		move_down(t_win *win)
{
	t_map	*map;

	win=win;
	map = ft_init_map(NULL);
}

void		move_left(t_win *win)
{
	t_map	*map;

	win=win;
	map = ft_init_map(NULL);
}

void		move_right(t_win *win)
{
	t_map	*map;

	win=win;
	map = ft_init_map(NULL);
}

t_funmove	*init_moves(void)
{
	t_funmove	*tab;

	tab = (t_funmove*)malloc(sizeof(t_funmove) * 4);
	tab[MVUP] = move_up;
	tab[MVDOWN] = move_down;
	tab[MVLEFT] = move_left;
	tab[MVRIGHT] = move_right;
	return (tab);
}
