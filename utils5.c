#include "so_long.h"

static unsigned int	ft_to_rgb(int r, int g, int b)
{
	unsigned int	c;

	c = r;
	c = (c << 8) + g;
	c = (c << 8) + b;
	return (c);
}

static unsigned int	ft_get_n_draw(t_img *img, int x, int y)
{
	unsigned int	color;
	char			*ptr;

	ptr = img->data + (y * img->size_line + x * (img->bpp / 8));
	color = *(unsigned int *)ptr;
	return (color);
}

static void	ft_put_pxl(t_img *mlx_img, int x, int y, int col)
{
	char	*target;

	target = mlx_img->data;
	target += x * mlx_img->bpp / 8 + y * mlx_img->size_line;
	*(unsigned int *)target = col;
}

void	ft_draw_cell(t_game *g, t_img *img, int x, int y)
{
	int				l;
	int				c;
	unsigned int	col;

	l = -1;
	while (++l < 64)
	{
		c = -1;
		while (++c < 64)
		{
			col = ft_get_n_draw(img, c, l);
			if (col != ft_to_rgb(0, 0, 0))
				ft_put_pxl(g->path.mlx_img, x * 64 + c, y * 64 + l, col);
		}
	}
}

void	ft_init_game(t_game *g)
{
	g->num_exit = 0;
	g->num_hero = 0;
	g->num_cook = 0;
	g->got_cook = 0;
	g->path.mlx_ptr = 0;
	g->path.mlx_img = 0;
	g->path.mlx_win = 0;
	g->path.hero = 0;
	g->path.exit = 0;
	g->path.wall = 0;
	g->path.back = 0;
	g->path.cook = 0;
	g->mv.mv_dw = 0;
	g->mv.mv_lf = 0;
	g->mv.mv_rt = 0;
	g->mv.mv_lf = 0;
	g->map.width = 0;
	g->map.height = 0;
}
