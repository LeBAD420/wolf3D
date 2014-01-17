#include "wolf3d.h"

void	ft_draw_wall(int h_wall, int x, int y, int color)
{
	t_win	*window;

	window = init_env();
	while (y < WIN_HEI / 2 + h_wall / 2 - 1)
	{
		mlx_put_pixel_to_image(x, y, color);
		y++;
	}
}

void	ft_draw_floor(int x, int y)
{
	t_win	*window;

	window = init_env();
	while (y < WIN_HEI - 1)
	{
		mlx_put_pixel_to_image(x, y, COLOR_FLOOR);
		y++;
	}
}

void	ft_draw_ceiling(int x, int y)
{
	t_win	*window;

	window = init_env();
	while (y > 0)
	{
		mlx_put_pixel_to_image(x, y, COLOR_CEILING);
		y--;
	}
}

void	ft_draw_img()
{
	int			x;
	int			y;
	double		wall_height;
	t_wall		wall;

	x = WIN_WID - 1;
	while (x >= 0)
	{
		wall = ft_wall_distance(x);
		wall_height = STEP / wall.dist * POV;

		/* Si hauteur du mur superieur hauteur fenetre on resize */
		if (wall_height > WIN_HEI)
			wall_height = WIN_HEI - 1;
		printf("Hauteur = %f et x = %d\n", wall_height, x);

		y = (WIN_HEI / 2) - 1 - (wall_height / 2);

		/* on dessine le plafond */
		ft_draw_ceiling(x, y);

		/* on dessine le mur */
		ft_draw_wall(wall_height, x, y, wall.color);

		/* on dessine le floor */
		ft_draw_floor(x, WIN_HEI / 2 + wall_height / 2 - 1);
		x--;
		/*if (x == WIN_WID - 300)
			break ;*/
	}
}

void	mlx_put_pixel_to_image(int x, int y, int color)
{
	unsigned int	new_color;
	int				i;
	t_win			*win;

	win = init_env();
	new_color = mlx_get_color_value(win->mlx, color);
	i = x * 4 + y * win->img->size_line;
	win->img->data[i] = (new_color & 0xFF);
	win->img->data[i + 1] = (new_color & 0xFF00) >> 8;
	win->img->data[i + 2] = (new_color & 0xFF0000) >> 16;
}
