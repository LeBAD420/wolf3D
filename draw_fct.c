#include "wolf3d.h"

void	ft_draw(t_win window, int wall_dist, int pix)
{
	int		wall_h;
	int		y;

	wall_h = (STEP / wall_dist) * POV;
	y = WIN_WID / 2 - 1 - wall_h / 2;
	while (y < WIN_WID / 2 - 1 + wall_h / 2)
	{
		mlx_pixel_put(window.mlx, window.win, pix, y, 0xFFFFFF);
		y++;
	}
}
