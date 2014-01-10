#include "./includes/wolf3d.h"

static int		ft_count_line(map)
{
	int		i;

	i = 0;
	if (!map)
		return (0)
	while (ft_strcmp(map[i], "\0"))
		i++;
	return (i);
}

static char		**ft_realloc(char **map, int count, char *line)
{
	char	**map;
	int		i;

	i = 0;
	if (!(map = (char **)malloc(sizeof(char *) * (i + 1))))
		ft_error("malloc (map) error");
	while (i < count)
		i++;
	map[i] = ft_strdup(line);
	map[i + 1] = ft_strdup("\0");
	return (map);
}

char			**ft_read(t_win *window)
{
	t_map	map;
	char	*line;
	int		count;

	count = 0;
	while ((ret = get_next_line(window->fd, &line)))
	{
		count = ft_count_line(map);
		map.lines = ft_realloc(map, count + 1);
	}
	map.l_num = count + 1;
	map.l_col = (int)ft_strlen(map.lines[0]);
	return (map);
}
