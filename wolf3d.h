#ifndef WOLF3D_H
# define WOLF3D_H

# include <math.h>
# include <mlx.h>

# define WIN_WID 320
# define WIN_LEN 640
# define FOV 60
# define POS (WIN_LEN/2)/(tanf(FOV/2))

typedef struct	s_win
{
	void	*mlx;
	void	*win;
	int		fd;
	int		echap;
}				t_win;

void	ft_read_and_print(t_win *window);

#endif
