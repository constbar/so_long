#include "../so_long.h"

static void	ft_get_position(t_game *g, int x, int y)
{
	static int	i = 0;

	if (g->map.map[y][x] == 'P')
	{
		g->hero.x = x;
		g->hero.y = y;
		g->map.map[y][x] = '0';
	}
	if (g->map.map[y][x] == 'E')
	{
		g->exit.x = x;
		g->exit.y = y;
		g->map.map[y][x] = '0';
	}
	if (g->map.map[y][x] == 'C')
	{
		g->cook[i].x = x;
		g->cook[i].y = y;
		g->map.map[y][x] = '0';
		i++;
	}
}

void	ft_map_parsing(t_game *g)
{
	int	x;
	int	y;

	if (g->num_hero != 1)
		ft_elim_bad(g, "i shoud be the only one pirate! arrr!");
	if (g->num_exit != 1)
		ft_elim_bad(g, "i have only the one Black Pearl! arr!");
	if (g->num_cook < 1)
		ft_elim_bad(g, "what have i do here without rum?!");
	y = -1;
	while (++y < g->map.height)
	{
		x = -1;
		while (++x < g->map.width)
			ft_get_position(g, x, y);
	}
}

void	ft_check_map(t_game *g, int x, int y)
{
	y = -1;
	while (++y < g->map.height)
	{
		x = -1;
		while (++x < g->map.width)
		{
			if ((g->map.map[0][x] != '1') ||
			g->map.map[g->map.height - 1][x] != '1')
				ft_elim_bad(g, "bad borders");
			if (g->map.map[y][0] != '1' ||
			g->map.map[y][g->map.width - 1] != '1')
				ft_elim_bad(g, "bad borders");
			if (g->map.map[y][x] == 'P')
				g->num_hero++;
			else if (g->map.map[y][x] == 'C')
				g->num_cook++;
			else if (g->map.map[y][x] == 'E')
				g->num_exit++;
			else if (g->map.map[y][x] == '1' || g->map.map[y][x] == '0')
				;
			else
				ft_elim_bad(g, "bad characters in the map");
		}
	}
}

void	ft_init_map(t_game *g, char *name)
{
	int		i;
	int		fd;
	char	*tmp;
	char	*line;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		ft_elim_bad(g, "invalid file");
	g->map.map = malloc((sizeof(char *)) * g->map.height);
	if (!g->map.map)
		ft_elim_bad(g, "malloc error");
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		tmp = ft_strtrim(line, " ");
		g->map.map[i] = ft_strdup(tmp);
		free(tmp);
		free(line);
		i++;
	}
	free(line);
	close(fd);
	if (g->map.width < 3 || g->map.height < 3)
		ft_elim_bad(g, "width or height should be more than 3 cells");
}

void	ft_open_map(t_game *g, char *name, int i, int fd)
{
	char	*tmp;
	char	*line;

	i = 0;
	fd = open(name, O_RDONLY);
	if (fd < 0)
		ft_elim_bad(g, "invalid file");
	g->map.width = 0;
	g->map.height = 0;
	while ((get_next_line(fd, &line) == 1) && line[0] != '\0')
	{
		tmp = ft_strtrim(line, " ");
		if (g->map.width != 0 && (ft_strlen(tmp) != g->map.width))
			ft_elim_bad(g, "invalid map");
		if (tmp[0] == '1' || tmp[0] == ' ')
			g->map.height++;
		else
			ft_elim_bad(g, "invalid map");
		g->map.width = ft_strlen(tmp);
		free(line);
		free(tmp);
	}
	free(line);
	close(fd);
}
