#include "./includes/wolf3d.h"

t_map			*ft_init_map(char *file_map)
{
	int			fd;
	t_map		*map;

	if ((fd = open(file_map, O_RDONLY)) == -1)
		ft_error("Impossible to open file_map");
	map = (t_map*)malloc(sizeof(t_map));
	map->start = (t_pos*)malloc(sizeof(t_pos));
	ft_read_map(fd, map);
	if (!ft_get_start_player(map))
		ft_error("No player in this map");
	return (map);
}

int				ft_get_start_player(t_map *map)
{
	t_pos		*pos;

	pos = pos_init(0, 0);
	while (pos->y < map->row)
	{
		while (pos->x < map->col)
		{
			if (map->maze[pos->y][pos->x] == STARTPLAYER)
			{
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
	if (maze == NULL)
		return ((char**)malloc(sizeof(char*) * (nbr)));
	new_maze = (char**)malloc(sizeof(char*) * (nbr));
	while (i < nbr - 1)
	{
		new_maze[i] = (char*)malloc(ft_strlen(maze[i]));
		new_maze[i] = maze[i];
		i++;
	}
	return (new_maze);
}

void			ft_read_map(int fd, t_map *map)
{
	char	**maze;
	char	*line;
	int		count;

	count = 0;
	maze = NULL;
	maze = (char**)malloc(sizeof(char*));
	while (get_next_line(fd, &line) > 0)
	{
		maze = ft_resize_maze(maze, count + 1);
		maze[count] = ft_strdup(line);
		count++;
	}
	map->row = count;
	map->col = ft_strlen(maze[0]);
	map->maze = maze;
	close(fd);
}

void			ft_del_map(t_map *map)
{
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
