/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 23:03:35 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/13 17:45:08 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	put_img(t_global *global, char c, int x, int y)
{
	mlx_put_image_to_window(global->game_cntl.mlx, global->game_cntl.win,
		global->assets.space, y, x);
	if (c == '1')
		mlx_put_image_to_window(global->game_cntl.mlx, global->game_cntl.win,
			global->assets.wall, y, x);
	else if (c == 'P')
		mlx_put_image_to_window(global->game_cntl.mlx, global->game_cntl.win,
			global->assets.player, y, x);
	else if (c == 'E')
		mlx_put_image_to_window(global->game_cntl.mlx, global->game_cntl.win,
			global->assets.exit_game[global->game_cntl.exit_animate], y, x);
	else if (c == 'C')
		mlx_put_image_to_window(global->game_cntl.mlx, global->game_cntl.win,
			global->assets.collectable, y, x);
	else if (c == 'H')
		mlx_put_image_to_window(global->game_cntl.mlx, global->game_cntl.win,
			global->assets.enemy, y, x);
}

static void	render_images(t_global *global)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < global->map.width)
	{
		put_img(global, '0', i * 60, 0);
		i++;
	}
	i = 0;
	while (i < (global->map).height)
	{
		j = 0;
		while (j < (global->map).width)
		{
			put_img(global, global->map.table[i][j], (i + 1) * 60, j * 60);
			j++;
		}
		i++;
	}
}

static void	load_frames(t_global *global)
{
	char	*s;

	if (global->game_cntl.frame == 40)
	{
		move_enemies(global);
		global->game_cntl.frame = 0;
	}	
	else if (global->game_cntl.frame == 20
		|| global->game_cntl.frame == 40)
		global->game_cntl.exit_animate++;
	mlx_clear_window (global->game_cntl.mlx, global->game_cntl.win);
	if (global->game_cntl.exit_animate > 6)
		global->game_cntl.exit_animate = 0;
	render_images(global);
	mlx_string_put(global->game_cntl.mlx, global->game_cntl.win,
		10, 10, 0xFFFFFF, "moves: ");
	s = ft_itoa(global->game_cntl.player.player_moves);
	mlx_string_put(global->game_cntl.mlx, global->game_cntl.win,
		80, 10, 0xFFFFFF, s);
	free(s);
	global->game_cntl.frame++;
}

int	render(t_global *global)
{
	int	x;
	int	y;

	x = ((global->map.width * 60) / 2);
	y = ((global->map.height * 60) / 2);
	if (global->game_cntl.game_on == 1)
		load_frames(global);
	else if (global->game_cntl.game_on == -1)
	{
		mlx_clear_window(global->game_cntl.mlx, global->game_cntl.win);
		mlx_string_put(global->game_cntl.mlx, global->game_cntl.win,
			x - 120, y + 80, 0xFFFFFF, "You Lose, Shame on you!");
		mlx_put_image_to_window(global->game_cntl.mlx, global->game_cntl.win,
			global->assets.lose_image, x - 50, y - 50);
	}
	else if (global->game_cntl.game_on == 0)
	{
		mlx_clear_window(global->game_cntl.mlx, global->game_cntl.win);
		mlx_string_put(global->game_cntl.mlx, global->game_cntl.win,
			x - 60, y + 80, 0xFFFFFF, "Bingo !, YOU WIN");
		mlx_put_image_to_window(global->game_cntl.mlx, global->game_cntl.win,
			global->assets.win_game, x - 50, y - 50);
	}
	global->game_cntl.frame++;
	return (1);
}
