#ifndef WOLF3D_H
# define WOLF3D_H

# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <../libft/includes/libft.h>

//COLORS
# define COLOR_WHITE 0xCCCCCC
# define COLOR_RED 0xCC0000
# define COLOR_ORANGE 0xFF7700
# define COLOR_YELLOW 0xCCCC00
# define COLOR_GREEN 0x00CC00
# define COLOR_CYAN 0x00CCCC
# define COLOR_BLUE 0x0000CC
# define COLOR_MAGENTA 0xCC00CC
# define COLOR_BLACK 0x000000

//ENV
# define WIN_WID 1280
# define WIN_LEN 1100

//CAMERA
# define FOV M_PI / 3
//# define POV 277
# define POV (int)(WIN_LEN / 2 / tanf(FOV/2))
# define STARTANGLE M_PI / 2
# define PLAYERSTEP 30
# define PLAYERROT M_PI / 12

//MAP
# define WALL '*'
# define PATH ' '
# define STARTPLAYER 'D'
# define STEP 64
# define COLOR_CEILING COLOR_CYAN
# define COLOR_FLOOR COLOR_RED
# define COLOR_WALL COLOR_BLUE

//GETNEXTLINE
# define BUFF_SIZE 8

//KEY_HOOK
# define KEYECHAP 65307
# define KEYLEFT 65361
# define KEYUP 65362
# define KEYRIGHT 65363
# define KEYDOWN 65364

typedef struct			s_pos
{
	int				x;
	int				y;
}						t_pos;

typedef struct			s_pos2
{
	double				x;
	double				y;
}						t_pos2;

typedef struct			s_map
{
	char			**maze;
	int				col;
	int				row;
	t_pos			*start;
}						t_map;

typedef struct 			s_img
{
	void			*img;
	char			*data;
	int				bbp;
	int				size_line;
	int				endian;
}						t_img;

typedef struct			s_win
{
	void			*mlx;
	void			*win;
	t_img			*img;
}						t_win;

typedef struct			s_cam
{
	t_pos			*pos;
	double			angle;
}						t_cam;

/*
** camera_fct.c
*/
t_cam			*ft_new_camera(t_pos *pos, double angle);
void			ft_set_camera(t_pos *pos, double angle);
void			ft_del_camera(void);

/*
** map_fct.c
*/
t_map			*ft_init_map(char *file_map);
int				ft_get_start_player(void);
char			**ft_resize_maze(char **maze, int nbr);
void			ft_read_map(int fd);
void			ft_del_map(void);

/*
** move_fct.c
*/
void			move_up(void);
void			move_down(void);
void			move_left(void);
void			move_right(void);

/*
** detect_fct.c
*/
double				ft_wall_distance(int i);

/*
** error_fct.c
*/
void			ft_error(char *s);

/*
** hook_fct.c
*/
int				ft_key_hook(int keycode);
int				ft_expose_hook(void);

/*
** draw.c
*/
void			ft_draw_wall(int h_wall, int x, int y);
void			ft_draw_floor(int x, int y);
void			ft_draw_ceiling(int x, int y);
void			ft_draw_img();
void			mlx_put_pixel_to_image(int x, int y, int color);

/*
** ft_get_next_line.c
*/
int				get_next_line(int const fd, char **line);

/*
** env_fct.c
*/
t_win			*init_env(void);
void			env_del(void);

/*
** img_fct.c
*/
t_img			*init_img(void);
void			img_del(t_img *img);

/*
** pos_fct.c
*/
t_pos			*pos_init(int x, int y);
void			pos_del(t_pos *pos);

#endif /* !WOLF3D_H */
