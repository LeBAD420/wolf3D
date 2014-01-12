#include "wolf3d.h"

void	ft_draw_wall(int h_wall, int x, int y)
{
	t_win	*window;

	window = init_env();
	while (y < WIN_LEN / 2 + h_wall / 2)
	{
		mlx_put_pixel_to_image(window, x, y, COLOR_FLOOR);
		y++;
	}
}

void	ft_draw_floor(int x, int y)
{
	t_win	*window;

	window = init_env();
	while (y < WIN_LEN)
	{
		mlx_put_pixel_to_image(window, x, y, COLOR_FLOOR);
		y++;
	}
}

void	ft_draw_ceiling(int x, int y)
{
	t_win	*window;

	window = init_env();
	while (y > 0)
	{
		mlx_put_pixel_to_image(window, x, y, COLOR_CEILING);
		y--;
	}
}

void	ft_draw_img()
{
	int		x;
	int		y;
	int		wall_height;
	int		wall_dist;

	x = 0;
	while (x < WIN_LEN)
	{
		wall_dist = ft_wall_distance(x);
		wall_height = (STEP / wall_dist) * POV;
		y = (WIN_WID / 2) - 1 - (wall_height / 2);

		/* on dessine le plafond */
		ft_draw_ceiling(x, y);

		/* on dessine le mur */
		ft_draw_wall(wall_height, x, WIN_LEN / 2 - wall_height / 2);

		/* on dessine le floor */
		ft_draw_floor(x, y);
		x++;

	}
}

void	mlx_put_pixel_to_image(t_win *win, int x, int y, int color)
{
	unsigned int	new_color;
	int				i;

	new_color = mlx_get_color_value(win->mlx, color);
	i = x * 4 + y * win->img->size_line;
	win->img->data[i] = new_color % 256;
	new_color /= 256;
	win->img->data[i + 1] = new_color % 256;
	new_color /= 256;
	win->img->data[i + 2] = new_color % 256;
	new_color /= 256;
	win->img->data[i + 3] = 0;
}
