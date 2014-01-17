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

/*
** Env
*/
# define WIN_HEI 1100
# define WIN_WID 2080

/*
** Map
*/
# define WALL '*'
# define PATH ' '
# define STARTPLAYER 'D'
# define STEP (WIN_WID * 30)
# define COLOR_CEILING 0x9EE1E8
# define COLOR_FLOOR 0xA7ABAB
# define COLOR_WALL_NORTH 0xAD131D
# define COLOR_WALL_SOUTH 0xD0131D
# define COLOR_WALL_EAST 0x99131D
# define COLOR_WALL_WEST 0x55131D

/*
** Camera
*/
# define FOV (M_PI / 3)
# define POV (WIN_WID / 2 / tan(FOV / 2))
# define STARTANGLE (M_PI / 2)
# define PLAYERSTEP (STEP / 2)
# define PLAYERROT (M_PI / 12)

/*
** Getnexline
*/
# define BUFF_SIZE 8

/*
** Couleur
*/
# define KEYECHAP				65307
# define KEYLEFT				65361
# define KEYUP					65362
# define KEYRIGHT				65363
# define KEYDOWN				65364

typedef struct			s_wall
{
	double			dist;
	int				color;
}						t_wall;

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
	t_pos2			*start;
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
	int 			save[4];
}						t_win;

typedef struct			s_cam
{
	t_pos2			*pos;
	double			angle;
}						t_cam;

/*
** camera_fct.c
*/
t_cam			*ft_new_camera(t_pos2 *pos, double angle);
void			ft_set_camera(t_pos2 *pos, double angle);
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
** hook_fct.c
*/
int				ft_expose_hook(t_win	*window);
int 			ft_keypress(int keycode, t_win *window);
int 			ft_key_release(int keycode, t_win *window);
void			ft_exit(void);
int				ft_loop_hook(t_win	*window);

/*
** draw.c
*/
void			ft_draw_wall(int h_wall, int x, int y, int color);
void			ft_draw_floor(int x, int y);
void			ft_draw_ceiling(int x, int y);
void			ft_draw_img();
void			mlx_put_pixel_to_image(int x, int y, int color);

/*
** horizontal_fct.c
*/
t_wall			ft_h_intersection(int i);
t_pos2			*first_h_inter(double va);
t_pos2			*next_h_inter(double va, t_pos2 *oi);

/*
** vertical_fct.c
*/
t_wall			ft_v_intersection(int i);
t_pos2			*first_v_inter(double va);
t_pos2			*next_v_inter(double va, t_pos2 *oi);

/*
** dist_fct.c
*/
t_wall			get_distance_h(double va, t_pos2 *inter);
t_wall			get_distance_v(double va, t_pos2 *inter);
t_wall			ft_wall_distance(int i);
t_wall			ft_dist_correction(int i, t_wall wall);

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
t_pos2			*pos_init(double x, double y);
void			pos_del(t_pos2 *pos);

/*
** detect_fct.c
*/
int				is_to_far(t_pos2 *pos);
int				is_wall(t_pos2 *pos);
int				looking_north(double va);
int				looking_east(double va);

/*
** error_fct.c
*/
void			ft_error(char *s);

#endif /* !WOLF3D_H */
