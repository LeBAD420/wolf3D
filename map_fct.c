#include "./includes/wolf3d.h"

t_map			*ft_init_map(char *file_map)
{
	int				fd;
	static t_map	*map = NULL;

	if (map == NULL)
	{
		if ((fd = open(file_map, O_RDONLY)) == -1)
			ft_error("Impossible to open file_map.");
		map = (t_map*)malloc(sizeof(t_map));
		map->start = (t_pos*)malloc(sizeof(t_pos));
		ft_read_map(fd);
		if (!ft_get_start_player())
			ft_error("No player in this map.");
	}
	return (map);
}

int				ft_get_start_player(void)
{
	t_pos		*pos;
	t_map		*map;

	map = ft_init_map(NULL);
	pos = pos_init(0, 0);
	while (pos->y < map->row)
	{
		while (pos->x < map->col)
		{
			if (map->maze[pos->y][pos->x] == STARTPLAYER)
			{
				map->maze[pos->y][pos->x] = PATH;
				pos->x = pos->x * STEP - 1;
				pos->y = pos->y * STEP - 1;
				map->start = pos;

				return (1);
			}
			pos->x++;
		}
		pos->x = 0;
		pos->y++;
	}
	return (0);
}

char			**ft_resize_maze(char **maze, int nbr)
{
	int			i;
	char		**new_maze;

	i = 0;
	new_maze = (char**)malloc(sizeof(char*) * (nbr));
	while (i < nbr - 1)
	{
		new_maze[i] = ft_strdup(maze[i]);
		i++;
	}
	return (new_maze);
}

void			ft_read_map(int fd)
{
	int		ret;
	char	**maze;
	char	*line;
	int		count;
	t_map	*map;

	map = ft_init_map(NULL);
	count = 0;
	maze = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		maze = ft_resize_maze(maze, count + 1);
		maze[count] = ft_strdup(line);
		count++;
	}
	if (ret == -1)
		ft_error("Reading error.");
	map->row = count;
	map->col = ft_strlen(maze[0]);
	map->maze = maze;
	close(fd);
}

void			ft_del_map(void)
{
	t_map	*map;

	map = ft_init_map(NULL);
	while(map->row)
	{
		free(map->maze[map->row]);
		map->row--;
	}
	map->maze = NULL;
	free(map->start);
	map->start = NULL;
	free(map);
	map = NULL;
}
