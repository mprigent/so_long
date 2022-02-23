/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <mprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:19:52 by mprigent          #+#    #+#             */
/*   Updated: 2021/11/02 20:01:59 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

# if defined(__APPLE__) && defined(__MACH__)
#  define ADVANCE 13
#  define BACK 1
#  define RIGHT 2
#  define LEFT 0
#  define ESC 53
#  define RED_BUTTON 79
#  define CLOSERED 17
# else
#  define ADVANCE 119
#  define BACK 115
#  define RIGHT 100
#  define LEFT 97
#  define ESC 65307
#  define RED_BUTTON 79
#  define CLOSERED 33
# endif

# define INVALID_ARGS "Usage : (./so_long maps/map.ber)."
# define NOT_VALID_FILE "Not a valid .ber file."
# define NOT_RECTANGULAR "The map is not rectangular."
# define NOT_CLOSED "The map is not closed by walls."
# define MISSING_PLAYER_POS "Can't find player position in the map."
# define INVALID_CHARACTER "Map contain invalid character."
# define NO_EXIT_GATE "Map does not contain exit gate."
# define NOT_VALID_MAP "Not a valid map."
# define CANT_EXIT "Can't exit : you didn't collect all collectibles"
# define MALLOC_ERROR "Malloc error."
# define MLX_ERROR "Mlx_init failed."
# define TEXT_ERROR "Texture loading failed."

typedef struct s_long{
	int		x_screen;
	int		y_screen;
	int		y;
	int		x;
	char	**map;
	int		move_count;
	int		free_map;
	void	*mlx;
	void	*win;
	void	*img;
	char	*pxl;
	void	*text[6];
	int		bits_per_pxl[6];
	int		s_line[6];
	char	*text_ptr[6];
	int		ed_text[6];
	int		y_text[6];
	int		x_text[6];
	int		keyboard[70000];
	int		set_player;
	int		set_exit;
	int		set_collectibles;
	int		collectibles;
	int		player_x;
	int		player_y;
	int		lastplayer_x;
	int		lastplayer_y;
	int		allx;
	int		j;
	int		u;
	int		d;
	int		t;
}	t_long;

int				ft_open_window(t_long *conf);
int				ft_init_window(t_long *conf);
int				get_next_line(int fd, char **lines);
size_t			ft_strlen(const char *s);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putnbr(int nb);
void			ft_putendl_fd(char *s, int fd);
int				ft_parse(t_long *conf, char *argv);
int				ft_ber_check(char *str, t_long *conf);
int				ft_print_err(char *msg);
int				ft_exit_free(t_long *conf);
int				ft_free_map(t_long *conf);
int				ft_exit_free(t_long *conf);
int				ft_malloc_map(t_long *conf);
int				ft_init_var(t_long *conf);
int				ft_gnl_line(t_long *conf, char *line);
int				ft_check(char *str);
int				ft_get_coord(t_long *conf, char *so_long);
int				ft_stock_map(t_long *conf, char *so_long);
int				ft_check_map(t_long *conf);
int				ft_check_walls(t_long *conf, char *so_long);
int				ft_render(t_long *conf);
int				ft_display(t_long *conf);
void			ft_print_texture(t_long *conf, int starter_x,
					int starter_y, int texture);
unsigned int	ft_get_color_pxl(t_long *conf, int texturenum,
					int x_text, int y_text);
int				ft_load_text(t_long *conf);
int				ft_find_text(t_long *conf, int x, int y);
void			ft_pux_pxl(t_long *conf, int x, int y, unsigned int color);
int				ft_red_button(t_long *conf);
int				ft_pos_player(t_long *conf);
int				ft_key_hit(int keycode, t_long *conf);
int				ft_hooks(t_long *conf);
int				ft_move_player(t_long *conf, int nb);
int				ft_keyboard(t_long *conf);
int				ft_key_loop(t_long *conf);
int				ft_reset_keyboard(t_long *conf);
void			ft_collectibles(t_long *conf);
int				ft_load_text_bonus(t_long *conf);
int				ft_load_text_bonus2(t_long *conf);
int				ft_check_walls2(t_long *conf);
int				ft_init_var2(t_long *conf);
int				ft_mini(t_long *conf);
int				ft_move_count(t_long *conf, int nb);
int				ft_load_text2(t_long *conf);
int				ft_print_error2(t_long *conf, char *str);

#endif
