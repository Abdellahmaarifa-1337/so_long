/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_enemy_direction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:12:25 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/13 15:25:07 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	is_in_used(int x, int y, int **used)
{
	int	i;

	i = 0;
	while (used[i])
	{
		if (used[i][0] == x && used[i][1] == y)
			return (1);
		i++;
	}
	return (0);
}

// void	set_enemy_direction(t_global *global)
// {
// 	size_t	i;
// 	t_enemy	*enemy;
// 	int		**used;
// 	int		*pos;

// 	used = (int **)malloc(sizeof(int *) * global->game_cntl->enemy_count);
// 	if (!used)
// 		throw_error(0, global);
// 	i = 0;
// 	while (i < global->game_cntl->enemy_count)
// 		used[i++] = 0;
// 	i = 0;
// 	while (i < global->game_cntl->enemy_count)
// 	{
// 		pos = (int *)malloc(sizeof(int));
// 		if (!pos)
// 			throw_error(0, global);
// 		enemy = global->game_cntl->enemies_mv[i];
// 		if (enemy->direction == 0)
// 		{
// 			if (((size_t)enemy->x + 2 < global->map->height) && (global->map->table[enemy->x + 1][enemy->y] == '0'
// 				|| global->map->table[enemy->x + 1][enemy->y] == 'P')
// 				&& (!(is_in_used(enemy->x + 1, enemy->y, used))))
// 			{
// 				enemy->direction = 0;
// 				pos[0] = enemy->x + 1;
// 				pos[1] = enemy->y;
// 				used[i] = pos;
// 			}
// 			else if ((enemy->x - 1 > 0) && (global->map->table[enemy->x - 1][enemy->y] == '0'
// 				|| global->map->table[enemy->x - 1][enemy->y] == 'P')
// 				&& (!(is_in_used(enemy->x - 1, enemy->y, used))))
// 			{
// 				enemy->direction = 1;
// 				pos[0] = enemy->x - 1;
// 				pos[1] = enemy->y;
// 				used[i] = pos;
// 			}
// 			else
// 				enemy->direction = -1;
// 		}
// 		else if (enemy->direction == 1)
// 		{
// 			if (((size_t)enemy->x + 2 < global->map->height) && (global->map->table[enemy->x + 1][enemy->y] == '0'
// 				|| global->map->table[enemy->x + 1][enemy->y] == 'P')
// 				&& (!(is_in_used(enemy->x + 1, enemy->y, used))))
// 			{
// 				enemy->direction = 1;
// 				pos[0] = enemy->x - 1;
// 				pos[1] = enemy->y;
// 				used[i] = pos;
// 			}
// 			else if ((enemy->x - 1 > 0) && (global->map->table[enemy->x - 1][enemy->y] == '0'
// 				|| global->map->table[enemy->x - 1][enemy->y] == 'P')
// 				&& (!(is_in_used(enemy->x - 1, enemy->y, used))))
// 			{
// 				enemy->direction = 0;
// 				pos[0] = enemy->x - 1;
// 				pos[1] = enemy->y;
// 				used[i] = pos;
// 			}
// 			else
// 				enemy->direction = -1;
// 		} else
// 		{
// 			if ((enemy->x - 1 > 0) && (global->map->table[enemy->x - 1][enemy->y] == '0'
// 				|| global->map->table[enemy->x - 1][enemy->y] == 'P')
// 				&& (!(is_in_used(enemy->x - 1, enemy->y, used))))
// 			{
// 				enemy->direction = 0;
// 				pos[0] = enemy->x - 1;
// 				pos[1] = enemy->y;
// 				used[i] = pos;
// 			}
// 			if (((size_t)enemy->x + 2 < global->map->height) && (global->map->table[enemy->x + 1][enemy->y] == '0'
// 				|| global->map->table[enemy->x + 1][enemy->y] == 'P')
// 				&& (!(is_in_used(enemy->x + 1, enemy->y, used))))
// 			{
// 				enemy->direction = 1;
// 				pos[0] = enemy->x - 1;
// 				pos[1] = enemy->y;
// 				used[i] = pos;
// 			}
// 		}
// 		i++;
// 	}
// }
