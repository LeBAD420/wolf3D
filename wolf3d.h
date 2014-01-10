#ifndef WOLF3D_H
# define WOLF3D_H

# include <math.h>
# include <mlx.h>

# define WIN_WID 200
# define WIN_LEN 320
# define FOV 60
# define POV (int)(WIN_LEN/2)/(tanf(FOV/2))
# define WALL '*'
# define PATH ' '
# define STEP 64

typedef struct	s_win
{
	void	*mlx;
	void	*win;
	int		fd;
	int		echap;
}				t_win;

typedef struct	s_map
{
	char	**lines;
	int		l_num;
	int		c_num;
}				t_map;

void	ft_read(t_win *window);
void	ft_draw(t_win *window, char **map);

#endif
