#include "wolf3d.h"

void	ft_draw_wall(t_win *window)
{


}

void	ft_draw_floor(t_win *window, int x, int y)
{
	while (start_y < WIN_LEN)
	{
		mlx_pixel_put_to_image(window->img->data, x, y, color);
		start_y++;
	}
}

void	ft_draw_ceiling(t_win *window, int x, int y)
{
	while (y > 0)
	{
		mlx_pixel_put_to_image(window->img->data, x, y, color);
		y--;
	}
}

void	ft_draw_img()
{
	/* On boucle sur chaque rayon */
	while ()
	{
		/* on recupere la hauteur du mur */

		/* on dessine le mur */

		/* on dessine le plafond */

		/* on dessine le floor */

	}

	/* on Affiche l'img */
	mlx_put_image_to_window(window->mlx, window->win, window->img->img, 0, 0);
}

void	mlx_put_pixel_to_image(t_win *win, int x, int y, int color)
{




}
void	ft_draw(t_win *window, int wall_dist, int pix)
{
	int		wall_h;
	int		y;

	wall_h = (STEP / wall_dist) * POV;
	y = (WIN_WID / 2) - 1 - (wall_h / 2);
	while (y < WIN_WID / 2 - 1 + wall_h / 2)
	{
		mlx_pixel_put(window->mlx, window->win, pix, y, 0xFFFFFF);
		y++;
	}
}
