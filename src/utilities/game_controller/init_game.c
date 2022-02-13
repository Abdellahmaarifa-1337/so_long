/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 22:20:33 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/13 15:13:56 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	count_objs(t_global *global)
{
	size_t	i;
	size_t	j;
	int		enm_count;
	int		point_count;

	point_count = 0;
	enm_count = 0;
	i = 0;
	while (i < global->map->height)
	{
		j = 0;
		while (j < global->map->width)
		{
			if (global->map->table[i][j] == 'H')
				enm_count++;
			if (global->map->table[i][j] == 'C')
				point_count++;
			j++;
		}
		i++;
	}
	global->game_cntl->enemy_count = enm_count;
	global->game_cntl->total_point = point_count;
}

// static t_enemy	*get_enemy(size_t i, size_t j, t_global *global)
// {
// 	t_enemy	*enemy;
// 	enemy = (t_enemy *)malloc(sizeof(t_enemy));
// 	if (!enemy)
// 		throw_error(0, global);
// 	enemy->x = i;
// 	enemy->y = j;
// 	enemy->direction = 0;
// 	return (enemy);
// }

static void	set_obj_position(t_global *global)
{
	size_t	i;
	size_t	j;
	int		k;

	global->game_cntl->enemies_mv = (t_enemy*) malloc(sizeof(t_enemy) * global->game_cntl->enemy_count);
	if (!global->game_cntl->enemies_mv)
		throw_error(0, global);
	i = -1;
	k = 0;
	while (++i < global->map->height)
	{
		j = -1;
		while (++j < global->map->width)
		{
			if (global->map->table[i][j] == 'P')
			{
				global->game_cntl->player->player_position[0] = i;
				global->game_cntl->player->player_position[1] = j;
			}
			if (global->map->table[i][j] == 'H')
			{
				(global->game_cntl->enemies_mv[k]).x = i;
				(global->game_cntl->enemies_mv[k++]).y = j;
			}
		}
	}
}

void	init_game(t_global *global)
{
	global->game_cntl->player = (t_player *)malloc(sizeof(t_player));
	if (!global->game_cntl->player)
		throw_error(0, global);
	global->game_cntl->total_point = 0;
	global->game_cntl->player->current_point = 0;
	count_objs(global);
	global->game_cntl->exit_animate = 0;
	global->game_cntl->frame = 0;
	global->game_cntl->game_on = 1;
	global->game_cntl->player->player_moves = 0;
	set_obj_position(global);
	//set_enemy_direction(global);
}
