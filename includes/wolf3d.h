#ifndef WOLF3D_H
# define WOLF3D_H

# include <math.h>
# include <mlx.h>
# include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
# include <stdio.h>

# define WIN_WID 200
# define WIN_LEN 320
# define FOV 60
# define POV (int)(WIN_LEN / 2 / tanf(FOV/2))
# define WALL '*'
# define PATH ' '
# define STEP 64
# define STARTANGLE 90

typedef struct		s_win
{
	void			*mlx;
	void			*win;
	int				fd;
	int				echap;
}					t_win;

typedef struct		s_map
{
	char			**lines;
	int				l_num;
	int				c_num;
	int				start_x;
	int				start_y;
}					t_map;

typedef struct 		s_cam
{
	int				pos_x;
	int				pos_y;
	int				angle;
}					t_cam;

typedef struct 		s_img
{
	void			*img;
	char			*data;
	int				bbp;
	int				size_line;
	int				endian;
}					t_img;

/*
** camera_fct.c
*/
t_cam	*new_camera(int x, int y, int angle);
void	set_camera(t_cam *cam, int x, int y, int angle);
void	del_camera(t_cam *cam);

/*
** detect_fct.c
*/
void	ft_detect_wall(t_win window, t_cam *cam, t_map *map);

/*
** error_fct.c
*/
void	ft_error(char *s);

/*
** hook_fct.c
*/
int		ft_key_hook(int keycode, t_win *window);
int		ft_expose_hook(t_win *window);

/*
** read.c
*/
void	ft_read(t_win *window);

/*
** draw.c
*/
void	ft_draw(t_win window, t_cam *cam, t_map *map);

#endif /* !WOLF3D_H */
