#ifndef SO_LONG_H
# define SO_LONG_H

# include <errno.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "./minilibX/mlx.h"
# include "./minilibX/mlx_int.h"

typedef struct s_xy
{
	int	x;
	int	y;
}				t_xy;

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
}				t_map;

typedef struct s_move
{
	int	mv_up;
	int	mv_dw;
	int	mv_lf;
	int	mv_rt;
}				t_move;

typedef struct s_path
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_img	*mlx_img;
	t_img	*hero;
	t_img	*wall;
	t_img	*exit;
	t_img	*cook;
	t_img	*back;
}				t_path;

typedef struct s_game
{
	int		num_hero;
	int		num_cook;
	int		num_exit;
	int		got_cook;
	t_xy	exit;
	t_xy	hero;
	t_xy	*cook;
	t_move	mv;
	t_map	map;
	t_path	path;
}				t_game;

// parse
void	ft_init_game(t_game *g);
void	ft_map_parsing(t_game *g);
void	ft_check_map(t_game *g, int x, int y);
void	ft_init_map(t_game *g, char *name);
void	ft_open_map(t_game *g, char *name, int x, int y);

// draw
void	ft_draw_wind(t_game *g);
void	ft_parse_text(t_path *p);
void	ft_draw_game(t_game *g, int x, int y);
void	ft_draw_cell(t_game *g, t_img *img, int x, int y);

// control
int		key_on(int key, t_game *g);
int		key_off(int key, t_game *g);

// errors
void	ft_error(char *str);
int		ft_elim_good(t_game *game);
int		ft_elim_bad(t_game *game, char *str);

// utils
void	ft_putnbr(int n);
void	ft_putchar(char c);
void	ft_putstr(char *str);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);
char	*ft_duplicate(const char *s);
char	*ft_copy(char *dst, char *src);
char	*ft_strchr(const char *s, int c);
int		get_next_line(int fd, char **line);
void	gnl_helper(char **pn, char **remains);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif