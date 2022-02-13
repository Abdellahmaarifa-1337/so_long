/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:21:04 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/13 17:44:25 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	move_enemy_up(t_global	*global, t_enemy enemy, int i)
{
	if (global->map.table[enemy.x - 1][enemy.y] == '0'
		|| global->map.table[enemy.x - 1][enemy.y] == 'P')
	{
		if (global->map.table[enemy.x - 1][enemy.y] == 'P')
		{
			mlx_clear_window(global->game_cntl.mlx, global->game_cntl.win);
			global->game_cntl.game_on = -1;
		}
		global->map.table[enemy.x][enemy.y] = '0';
		global->map.table[enemy.x - 1][enemy.y] = 'H';
		(global->game_cntl.enemies_mv[i]).x -= 1;
	}
}

void	move_enemy_right(t_global *global, t_enemy enemy, int i)
{
	if (global->map.table[enemy.x][enemy.y + 1] == '0' ||
		global->map.table[enemy.x][enemy.y + 1] == 'P')
	{
		if (global->map.table[enemy.x][enemy.y + 1] == 'P')
		{
			mlx_clear_window(global->game_cntl.mlx, global->game_cntl.win);
			global->game_cntl.game_on = -1;
		}
		global->map.table[enemy.x][enemy.y] = '0';
		global->map.table[enemy.x][enemy.y + 1] = 'H';
		(global->game_cntl.enemies_mv[i]).y += 1;
	}
}

void	move_enemy_down(t_global *global, t_enemy enemy, int i)
{
	if (global->map.table[enemy.x + 1][enemy.y] == '0' ||
		global->map.table[enemy.x + 1][enemy.y] == 'P')
	{
		if (global->map.table[enemy.x + 1][enemy.y] == 'P')
		{
			mlx_clear_window(global->game_cntl.mlx, global->game_cntl.win);
			global->game_cntl.game_on = -1;
		}
		global->map.table[enemy.x][enemy.y] = '0';
		global->map.table[enemy.x + 1][enemy.y] = 'H';
		(global->game_cntl.enemies_mv[i]).x += 1;
	}
}

void	move_enemy_left(t_global *global, t_enemy enemy, int i)
{
	if (global->map.table[enemy.x][enemy.y - 1] == '0' ||
		global->map.table[enemy.x][enemy.y - 1] == 'P')
	{
		if (global->map.table[enemy.x][enemy.y - 1] == 'P')
		{
			mlx_clear_window(global->game_cntl.mlx, global->game_cntl.win);
			global->game_cntl.game_on = -1;
		}
		global->map.table[enemy.x][enemy.y] = '0';
		global->map.table[enemy.x][enemy.y - 1] = 'H';
		(global->game_cntl.enemies_mv[i]).y -= 1;
	}
}

void	move_enemies(t_global *global)
{
	size_t	i;
	t_enemy	enemy;
	int		random;

	i = 0;
	while (i < global->game_cntl.enemy_count)
	{
		enemy = global->game_cntl.enemies_mv[i];
		random = rand() % 4;
		if (random == 0)
			move_enemy_up(global, enemy, i);
		else if (random == 1)
			move_enemy_right(global, enemy, i);
		else if (random == 2)
			move_enemy_down(global, enemy, i);
		else if (random == 3)
			move_enemy_left(global, enemy, i);
		i++;
	}
	return ;
}
