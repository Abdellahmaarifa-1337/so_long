/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 22:20:33 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/13 18:37:42 by amaarifa         ###   ########.fr       */
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
	while (i < global->map.height)
	{
		j = 0;
		while (j < global->map.width)
		{
			if (global->map.table[i][j] == 'H')
				enm_count++;
			if (global->map.table[i][j] == 'C')
				point_count++;
			j++;
		}
		i++;
	}
	global->game_cntl.enemy_count = enm_count;
	global->game_cntl.total_point = point_count;
}

void	set_position(t_global *global, size_t *position, char c, int *k)
{
	if (c == 'P')
	{
		global->game_cntl.player.player_position[0] = position[0];
		global->game_cntl.player.player_position[1] = position[1];
	}
	if (c == 'H')
	{
		(global->game_cntl.enemies_mv[*k]).x = position[0];
		(global->game_cntl.enemies_mv[*k]).y = position[1];
		*k += 1;
	}
}

static void	set_obj_position(t_global *global)
{
	size_t		i;
	size_t		j;
	int			k;
	size_t		position[2];

	global->game_cntl.enemies_mv = (t_enemy *) malloc(sizeof(t_enemy)
			* global->game_cntl.enemy_count);
	if (!global->game_cntl.enemies_mv)
		throw_error(0);
	i = -1;
	k = 0;
	while (++i < global->map.height)
	{
		j = -1;
		while (++j < global->map.width)
		{
			position[0] = i;
			position[1] = j;
			set_position(global, position, global->map.table[i][j], &k);
		}
	}
}

void	init_game(t_global *global)
{
	global->game_cntl.total_point = 0;
	global->game_cntl.player.current_point = 0;
	count_objs(global);
	global->game_cntl.exit_animate = 0;
	global->game_cntl.frame = 0;
	global->game_cntl.game_on = 1;
	global->game_cntl.player.player_moves = 0;
	set_obj_position(global);
}
