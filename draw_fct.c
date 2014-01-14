#include "wolf3d.h"

void	ft_draw_wall(int h_wall, int x, int y)
{
	t_win	*window;

	window = init_env();
	while (y < WIN_WID / 2 + h_wall / 2 - 1)
	{
		mlx_put_pixel_to_image(x, y, COLOR_WALL);
		y++;
	}
}

void	ft_draw_floor(int x, int y)
{
	t_win	*window;

	window = init_env();
	while (y < WIN_WID - 1)
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
	double		wall_dist;

	x = WIN_LEN - 1;
	while (x >= 0)
	{
		//printf("x = %d\n", x);
		wall_dist = ft_wall_distance(x);

		printf("Pour x = %d wall_dist->%f\n", x, wall_dist);
		//ft_putstr("\n");
		wall_height = STEP / wall_dist * POV;
		printf("hauteur a l ecran = %f\n", wall_height);
		/*if (wall_height > WIN_WID)
			wall_height = WIN_WID - 1;*/
		y = (WIN_WID / 2) - 1 - (wall_height / 2);

		/* on dessine le plafond */
		ft_draw_ceiling(x, y);

		/* on dessine le mur */
		ft_draw_wall(wall_height, x, y);

		/* on dessine le floor */
		ft_draw_floor(x, WIN_WID / 2 + wall_height / 2 - 1);
		/*if (x == WIN_LEN - 64)
			break ;
	*/	x--;

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
