#include "./includes/wolf3d.h"

void		move_up(void)
{
	t_cam	*cam;
	t_map	*map;
	int		new_x;
	int		new_y;

	cam = ft_new_camera(NULL, 0);
	map = ft_init_map(NULL);
	new_x = cam->pos->x + cos(cam->angle) * PLAYERSTEP;
	new_y = cam->pos->y + sin(cam->angle) * PLAYERSTEP;


	//Si on depasse de la map
	if ( new_y <= map->row * STEP && new_y > 0 &&
		new_x <= map->col *STEP && new_x > 0)
	{
		if (map->maze[new_y / STEP][new_x / STEP] == PATH)
		{
			printf("avance dans la map\n");
		printf("Ancienne coord camera x=%d, y = %d\n", cam->pos->x , cam->pos->y);
		//if ()
		printf("valeur de pas sur x =%f\n", cos(cam->angle) * PLAYERSTEP);
		cam->pos->x = new_x;
		cam->pos->y = new_y;
		printf("nouvelle coord camera x=%d, y = %d\n", cam->pos->x , cam->pos->y);
		}
		else
			printf("ona  rencontrer un mur\n");
	}
	else
		printf("avance en dehors de la map\n");

}

void		move_down(void)
{
	t_cam	*cam;
	t_map	*map;
	int		new_x;
	int		new_y;

	cam = ft_new_camera(NULL, 0);
	map = ft_init_map(NULL);
	new_x = cam->pos->x - cos(cam->angle) * PLAYERSTEP;
	new_y = cam->pos->y - sin(cam->angle) * PLAYERSTEP;

	//Si on depasse de la map
	if ( new_y <= map->row * STEP && new_y > 0 &&
		new_x <= map->col *STEP && new_x > 0)
	{
		if (map->maze[new_y / STEP][new_x / STEP] == PATH)
		{
			printf("recule dans la map\n");
		printf("Ancienne coord camera x=%d, y = %d\n", cam->pos->x , cam->pos->y);
		//if ()
		printf("valeur de pas sur x =%f\n", cos(cam->angle) * PLAYERSTEP);
		cam->pos->x -= cos(cam->angle) * PLAYERSTEP;
		cam->pos->y -= sin(cam->angle) * PLAYERSTEP;
		printf("nouvelle coord camera x=%d, y = %d\n", cam->pos->x , cam->pos->y);
		}
		else
			printf("on a rencontre un mur\n");

	}
	else
		printf("recule en dehors de la map\n");
}

void		move_left(void)
{
	t_cam	*cam;

	cam = ft_new_camera(NULL, 0);
	cam->angle += PLAYERROT;
	if (cam->angle - 2 * M_PI > 0)
		cam->angle = 0;
	printf("%f\n", cam->angle);

}

void		move_right(void)
{
	t_cam	*cam;

	cam = ft_new_camera(NULL, 0);
	cam->angle -= PLAYERROT;
	if (cam->angle < 0)
		cam->angle = 23 * M_PI / 12;
	printf("%f\n", cam->angle);
}


