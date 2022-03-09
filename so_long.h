/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leldiss <leldiss@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:14:04 by leldiss           #+#    #+#             */
/*   Updated: 2022/03/09 01:13:28 by leldiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define ESCAPE 65307
# define PLAYER "texture/player.xpm"
# define COLLECTIBLE "texture/gas.xpm"
# define EXIT "texture/helicopter.xpm"
# define FLOOR "texture/sand.xpm"
# define WALL "texture/wall.xpm"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include "stdarg.h"
# define STEP_X 40
# define STEP_Y 40

typedef struct s_root
{
	void	*window;
	void	*connection;
	int		player_x;
	int		player_y;
	int		playerx_matrix;
	int		playery_matrix;
	int		collect_count;
	void	*wall;
	void	*floor;
	void	*player;
	void	*door;
	void	*collectible;
	char	**map;
	int		linecount;
	int		linelength;
	int		x;
	int		y;
	int		e;
}	t_root;

typedef struct flags
{
	va_list	arg;
	int		len;
}	t_check_flag;

int				line_count(char *file_name);
int				first_line(int fd);
int				line_length(char *file_name);
t_root			map_fill(t_root root, char *file_name);
t_root			map_create(char *file_name, t_root root);
int				valid_char(t_root root, int y, int x);
int				valid_border(char c);
int				valid_map(t_root root);
void			free_map(t_root *root);
void			null_error(char *message);
int				error(char *message);
int				map_not_valid(t_root *root);
int				end_programm(t_root *root);

int				mouse_event(int button, int x, int y, void *param);
int				keyboard_event(int button, int x, int y, void *param);
t_root			draw_map(t_root root, char *file_name);
t_root			get_textures(t_root root);
t_root			draw_texture(t_root root, int i, int k);

int				close_window(int button, t_root *root);
int				move_player_up(t_root *root, int steps);
int				move_player_down(t_root *root, int steps);
int				move_player_left(t_root *root, int steps);
int				move_player_right(t_root *root, int steps);
int				special_move(t_root *root, int matrix_y,
					int matrix_x, int step);

int				destroy_hook(int keycode, t_root *root);
int				ft_strcmp(const char *s1, const char *s2);
int				isber(char *file_name);
int				valid_file(int argc, char *file_name);

int				ft_printchar(t_check_flag *flag, int i);
int				ft_abs(int n);
int				count_digits(int n);
char			*ft_itoa(int n);
int				ft_strlen(char *s);
int				ft_printdigit(t_check_flag *flag, int i);
int				ft_printstr(t_check_flag *flag, int i);
int				ft_len_hex(unsigned long long n);
char			ft_small_symbol(int n);
char			ft_big_symbol(int n);
char			*ft_itoa_address(unsigned long long n);
int				ft_printaddress(t_check_flag *flag, int i);
int				ft_uns_count(unsigned int n);
char			*ft_fill_uns_itoa(char *s, unsigned int n, int len);
char			*ft_itoa_uns(unsigned int n);
int				ft_printunsigned(t_check_flag *flag, int i);
char			*ft_itoa_small_hex(unsigned int x);
int				ft_printsmallhex(t_check_flag *flag, int i);
char			*ft_itoa_big_hex(unsigned int x);
int				ft_printbighex(t_check_flag *flag, int i);
int				parsflag(const char *format, t_check_flag *flag, int i);
int				ft_printf(const char *format, ...);

#endif
