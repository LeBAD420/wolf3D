#include "./includes/wolf3d.h"

t_map			*ft_init_map(char *file_map)
{
	int			fd;
	t_map		*map;

	if (!(fd = ft_open_map(file_map)))
		ft_error("Impossible to open file_map");
	map = (t_map*)malloc(sizeof(t_map));
	ft_read_map(fd, map);
	if (!ft_get_start_player(map))
		ft_error("No player in this map");
	return (map);
}

int				ft_get_start_player(t_map *map)
{
	int			x;
	int			y;

	x = 0;
	y = 0;
	while (y < map->row)
	{
		while (x < map->col)
		{
			if (map->maze[y][x] == STARTPLAYER)
			{
				map->start_x = x;
				map->start_y = y;
				return (1);
			}
			x++;
		}
		x = 0;
		y++;
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

int				ft_open_map(char *map_file)
{
	int		fd;

	fd = open(map_file, O_RDONLY);
    return (fd == -1 ? 0 : fd);
}
