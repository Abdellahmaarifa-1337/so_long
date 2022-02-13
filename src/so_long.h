/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:48:36 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/13 18:36:08 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"

/* THE MAP */
typedef struct s_map {
	char	**table;
	size_t	height;
	size_t	width;
}	t_map;

/* Player */

typedef struct s_player
{
	int		player_moves;
	size_t	current_point;
	int		player_position[2];
}	t_player;

/* THE ENEMY */
typedef struct s_enemy {
	int	x;
	int	y;
	int	direction;
}	t_enemy;

/* THE GAME CONTROLLER */
typedef struct s_game_cntl
{
	void		*win;
	void		*mlx;
	int			game_on;
	size_t		total_point;
	size_t		enemy_count;
	t_enemy		*enemies_mv;
	int			exit_animate;
	int			frame;
	t_player	player;
}	t_game_cntl;

/* THE GAME ASSETS */

typedef struct s_assets
{
	void	*exit_game[7];
	void	*collectable;
	void	*player;
	void	*enemy;
	void	*wall;
	void	*space;
	void	*win_game;
	void	*lose_image;
}	t_assets;

/* THE GLOBAL GAME STRUCTER */

typedef struct s_global
{
	t_map		map;
	t_game_cntl	game_cntl;
	t_assets	assets;
}	t_global;

/* ERRORS HANDLER */
void	throw_error(int error_code);

/* MAP PARSER */
t_map	*map_parser(char *map_file, t_global *global);
int		check_extension(char *map_file, char *ext);
void	count_lines(char *map_file, t_global *global);
void	fill_map(char *map_file, t_global *global);
int		map_chr(t_global *global, char c);

/* GAME CONTROLLER */
void	load_assets(t_global	*global);
void	init_game(t_global *t_global);
void	event_tracker(t_global *global, char c);
void	move_down(t_global *global);
void	move_up(t_global *global);
void	move_left(t_global *global);
void	move_right(t_global *global);
int		ft_close(int keycode);
int		render(t_global *global);
void	move_enemies(t_global *global);
/* GET NEXT LINE */
char	*get_next_line(int fd);

/* HELPERS FUNCTIONS */
void	ft_putstr(char *s);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char	*src);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
int		is_only_char(char *line, char *chars);
char	*trim_new_line(char *s);
void	ft_last_char(char *s, char *c);
char	*ft_itoa(int n);
/*_________________do not forget this--------*/
void	print_map(t_global *global);
#endif