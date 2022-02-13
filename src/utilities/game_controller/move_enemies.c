/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:21:04 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/13 15:11:32 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	move_enemies(t_global *global)
{
	size_t	i;
	t_enemy	enemy;
	int		random;

	i = 0;
	while (i < global->game_cntl->enemy_count)
	{
		enemy = global->game_cntl->enemies_mv[i];
		random = rand() % 4;
		if (random == 0)
		{
			if (global->map->table[enemy.x - 1][enemy.y] == '0'
				|| global->map->table[enemy.x - 1][enemy.y] == 'P')
			{
				if (global->map->table[enemy.x - 1][enemy.y] == 'P')
				{
					mlx_clear_window(global->game_cntl->mlx, global->game_cntl->win);
					global->game_cntl->game_on = -1;
				}
				global->map->table[enemy.x][enemy.y] = '0';
				global->map->table[enemy.x - 1][enemy.y] = 'H';
				(global->game_cntl->enemies_mv[i]).x -= 1;
				
			}
		}
		else if (random == 1)
		{
			if (global->map->table[enemy.x][enemy.y + 1] == '0' ||
				global->map->table[enemy.x][enemy.y + 1] == 'P')
			{
				if (global->map->table[enemy.x][enemy.y + 1] == 'P')
				{
					mlx_clear_window(global->game_cntl->mlx, global->game_cntl->win);
					global->game_cntl->game_on = -1;
				}
				global->map->table[enemy.x][enemy.y] = '0';
				global->map->table[enemy.x][enemy.y + 1] = 'H';
				(global->game_cntl->enemies_mv[i]).y += 1;
			}
		}
		else if (random == 2)
		{
			if (global->map->table[enemy.x + 1][enemy.y] == '0' ||
				global->map->table[enemy.x + 1][enemy.y] == 'P')
			{
				if (global->map->table[enemy.x + 1][enemy.y] == 'P')
				{
					mlx_clear_window(global->game_cntl->mlx, global->game_cntl->win);
					global->game_cntl->game_on = -1;
				}
				global->map->table[enemy.x][enemy.y] = '0';
				global->map->table[enemy.x + 1][enemy.y] = 'H';
				(global->game_cntl->enemies_mv[i]).x += 1;
			}
		}
		else if (random == 3)
		{
			if (global->map->table[enemy.x][enemy.y - 1] == '0' ||
				global->map->table[enemy.x][enemy.y - 1] == 'P')
			{
				if (global->map->table[enemy.x][enemy.y - 1] == 'P')
				{
					mlx_clear_window(global->game_cntl->mlx, global->game_cntl->win);
					global->game_cntl->game_on = -1;
				}
				global->map->table[enemy.x][enemy.y] = '0';
				global->map->table[enemy.x][enemy.y - 1] = 'H';
				(global->game_cntl->enemies_mv[i]).y -= 1;
			}
		}
		i++;
	}
	return ;
}
