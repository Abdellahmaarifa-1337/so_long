/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:34:20 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/10 20:30:49 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"
# define BUFFER_SIZE 500

typedef struct t_map {
	char		**line;
	size_t		height;
	size_t		width;
}	t_map;

typedef struct t_hook
{
	int x;
	int y;
	int direction;
} t_hook;

typedef struct global
{
	t_map	*map;
	t_hook	**hooks;
	int		hooks_size;
	int		**hook_move;
	void	*win;
	void	*mlx;
	int		img_nb;
	void	*holes_img[7];
	void	*leave_img;
	void	*player_img;
	void	*hook_img;
	void	*wall_img;
	void	*background_img;
	size_t	player_position[2];
	size_t	position[2];
	size_t	current_point;
	size_t	total_point;
	size_t	frame;
	int		move_down;
	int 	game_on;
	void	*img;
	int		moves_count;
}	t_global;

char	*get_next_line(int fd, int buffer_size);

/* HELPERS */
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
void	map_parsser(char *path, t_map **map);
void	throw_err(char *err, t_map **map);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char	*src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);


// MOVES
void	event_tracker(t_global *global, char c);
void	move_down(t_global *global);
void 	move(size_t *i, size_t *j, t_global *global, int direction);
void	move_up(t_global *global);
void	move_left(t_global *global);
void	move_right(t_global *global);
char	last_char(char *s);
/* SO_LONG HELPERS */
// void calc_direction_hooks(t_global *global);
int		render(t_global *global);
#endif