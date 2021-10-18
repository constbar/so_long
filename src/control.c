#include "../so_long.h"

static void	ft_print_helper(t_game *g, int move)
{
	ft_putstr("you have made ");
	ft_putnbr(move);
	ft_putstr(" moves\n");
}

static void	ft_cookie_helper(t_game *g, int i)
{
	g->cook[i].x = -21;
	g->cook[i].y = -21;
	g->got_cook++;
}

void	ft_draw_again(t_game *g, int x, int y, int i)
{
	static int	move = 0;

	x = g->hero.x;
	y = g->hero.y;
	if (g->mv.mv_rt == 21)
		if (g->map.map[y][x + 1] != '1')
			g->hero.x += 1;
	if (g->mv.mv_dw == 21)
		if (g->map.map[y + 1][x] != '1')
			g->hero.y += 1;
	if (g->mv.mv_lf == 21)
		if (g->map.map[y][x - 1] != '1')
			g->hero.x -= 1;
	if (g->mv.mv_up == 21)
		if (g->map.map[y - 1][x] != '1')
			g->hero.y -= 1;
	while (++i < g->num_cook)
		if (g->cook[i].x == g->hero.x && g->cook[i].y == g->hero.y)
			ft_cookie_helper(g, i);
	if ((g->hero.x != x || g->hero.y != y) && ++move)
		ft_print_helper(g, move);
	ft_draw_game(g, x, y);
	if (g->exit.x == g->hero.x && g->exit.y == g->hero.y)
		if (g->num_cook == g->got_cook)
			ft_elim_good(g);
}

int	key_on(int key, t_game *g)
{
	int	x;
	int	y;
	int	i;

	i = -1;
	if (key == 97)
		g->mv.mv_lf = 21;
	if (key == 100)
		g->mv.mv_rt = 21;
	if (key == 115)
		g->mv.mv_dw = 21;
	if (key == 119)
		g->mv.mv_up = 21;
	if (key == 65307)
		ft_elim_good(g);
	ft_draw_again(g, x, y, i);
	return (0);
}

int	key_off(int key, t_game *g)
{
	int	x;
	int	y;
	int	i;

	i = -1;
	if (key == 97)
		g->mv.mv_lf = 0;
	if (key == 100)
		g->mv.mv_rt = 0;
	if (key == 115)
		g->mv.mv_dw = 0;
	if (key == 119)
		g->mv.mv_up = 0;
	ft_draw_again(g, x, y, i);
	return (0);
}
