#include "so_long.h"

static void	ft_free_imgs(t_game *g)
{
	if (g->path.hero)
		mlx_destroy_image(g->path.mlx_ptr, g->path.hero);
	if (g->path.exit)
		mlx_destroy_image(g->path.mlx_ptr, g->path.exit);
	if (g->path.back)
		mlx_destroy_image(g->path.mlx_ptr, g->path.back);
	if (g->path.wall)
		mlx_destroy_image(g->path.mlx_ptr, g->path.wall);
	if (g->path.cook)
		mlx_destroy_image(g->path.mlx_ptr, g->path.cook);
}

int	ft_elim_bad(t_game *game, char *str)
{
	int	i;

	i = -1;
	ft_error(str);
	if (game)
	{
		ft_free_imgs(game);
		if (game->path.mlx_img)
			mlx_destroy_image(game->path.mlx_ptr, game->path.mlx_img);
		if (game->path.mlx_win)
			mlx_destroy_window(game->path.mlx_ptr, game->path.mlx_win);
		if (game->path.mlx_ptr)
			mlx_destroy_display(game->path.mlx_ptr);
		if (game->cook)
			free(game->cook);
		if (game->map.map)
		{
			while (++i < game->map.height)
				free(game->map.map[i]);
			free(game->map.map);
		}
	}
	exit(EXIT_FAILURE);
}

int	ft_elim_good(t_game *game)
{
	int	i;

	i = -1;
	ft_free_imgs(game);
	if (game->path.mlx_img)
		mlx_destroy_image(game->path.mlx_ptr, game->path.mlx_img);
	if (game->path.mlx_win)
		mlx_destroy_window(game->path.mlx_ptr, game->path.mlx_win);
	if (game->path.mlx_ptr)
		mlx_destroy_display(game->path.mlx_ptr);
	if (game->cook)
		free(game->cook);
	if (game->map.map)
	{
		while (++i < game->map.height)
			free(game->map.map[i]);
		free(game->map.map);
	}
	exit(EXIT_SUCCESS);
}

void	ft_game(char *file)
{
	int		x;
	int		y;
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	ft_init_game(&game);
	ft_open_map(&game, file, x, y);
	ft_init_map(&game, file);
	ft_check_map(&game, x, y);
	game.cook = malloc(sizeof(t_xy) * game.num_cook);
	ft_map_parsing(&game);
	ft_draw_wind(&game);
	ft_draw_game(&game, x, y);
	mlx_hook(game.path.mlx_win, 2, 1L << 0, key_on, &game);
	mlx_hook(game.path.mlx_win, 3, 1L << 1, key_off, &game);
	mlx_hook(game.path.mlx_win, 17, 1L << 17, ft_elim_good, &game);
	mlx_loop(game.path.mlx_ptr);
}

int	main(int argc, char *argv[])
{
	int	cmp;

	if (argc != 2)
		ft_elim_bad(0, "need 2 arguments");
	cmp = ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4);
	if (ft_strlen(argv[1]) < 5 || cmp != 0)
		ft_elim_bad(0, "need correct map file");
	ft_game(argv[1]);
	return (0);
}
