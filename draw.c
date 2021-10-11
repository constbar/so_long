#include "so_long.h"

void	ft_draw_game(t_game *g, int x, int y)
{
	int	i;

	y = -1;
	while (++y < g->map.height)
	{
		x = -1;
		while (++x < g->map.width)
		{
			i = -1;
			if (g->map.map[y][x] == '0')
				ft_draw_cell(g, g->path.back, x, y);
			if (g->map.map[y][x] == '1')
				ft_draw_cell(g, g->path.wall, x, y);
			if (g->exit.x == x && g->exit.y == y)
				ft_draw_cell(g, g->path.exit, x, y);
			if (g->hero.x == x && g->hero.y == y)
				ft_draw_cell(g, g->path.hero, x, y);
			while (++i < g->num_cook)
				if (g->cook[i].x == x && g->cook[i].y == y)
					ft_draw_cell(g, g->path.cook, x, y);
		}
	}
	mlx_put_image_to_window(g->path.mlx_ptr, \
	g->path.mlx_win, g->path.mlx_img, 0, 0);
}

static void	ft_get_text(t_game *g, t_img **img, char *path)
{
	int	a;
	int	b;

	*img = mlx_xpm_file_to_image(g->path.mlx_ptr, path, &a, &b);
	if (!*img)
		ft_elim_bad(g, "minilibX err");
	(*img)->width = a;
	(*img)->height = b;
}

void	ft_draw_wind(t_game *g)
{
	g->path.mlx_ptr = mlx_init();
	if (!g->path.mlx_ptr)
		ft_elim_bad(g, "minilibX err");
	g->path.mlx_win = mlx_new_window(g->path.mlx_ptr, \
	g->map.width * 64, g->map.height * 64, \
	"help to the pirate to find freedom");
	if (!g->path.mlx_win)
		ft_elim_bad(g, "minilibX err");
	g->path.mlx_img = mlx_new_image(g->path.mlx_ptr, \
	g->map.width * 64, g->map.height * 64);
	if (!g->path.mlx_img)
		ft_elim_bad(g, "minilibX err");
	ft_get_text(g, &g->path.back, "./imgs/back.xpm");
	ft_get_text(g, &g->path.wall, "./imgs/wall.xpm");
	ft_get_text(g, &g->path.exit, "./imgs/exit.xpm");
	ft_get_text(g, &g->path.hero, "./imgs/hero.xpm");
	ft_get_text(g, &g->path.cook, "./imgs/cook.xpm");
}
