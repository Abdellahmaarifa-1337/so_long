/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:39:49 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/13 17:44:31 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	event_tracker(t_global *global, char c)
{
	if (c == 'H' && global->game_cntl.game_on == 1)
			global->game_cntl.game_on = -1;
	else if (global->game_cntl.player.current_point
		== global->game_cntl.total_point
		&& c == 'E' && global->game_cntl.game_on == 1)
				global->game_cntl.game_on = 0;
}

void	move_down(t_global *global)
{
	char		*p;
	size_t		i;
	size_t		j;

	i = global->game_cntl.player.player_position[0];
	j = global->game_cntl.player.player_position[1];
	if (i < global->map.height - 2)
	{
		p = &(global->map.table[i + 1][j]);
		if (*p != '1')
		{
			if (*p != 'E' && *p != 'H')
			{
				if (*p == 'C')
					global->game_cntl.player.current_point++;
				global->map.table[i][j] = '0';
				*p = 'P';
				global->game_cntl.player.player_position[0] += 1;
				global->game_cntl.player.player_moves++;
			}
			event_tracker(global, *p);
		}
	}
}

void	move_up(t_global *global)
{
	char	*p;
	size_t	i;
	size_t	j;

	i = global->game_cntl.player.player_position[0];
	j = global->game_cntl.player.player_position[1];
	if (i > 1)
	{
		p = &(global->map.table[i - 1][j]);
		if (*p != '1')
		{
			if (*p != 'E' && *p != 'H')
			{
				if (*p == 'C')
					global->game_cntl.player.current_point++;
				global->map.table[i][j] = '0';
				*p = 'P';
				global->game_cntl.player.player_position[0] -= 1;
				global->game_cntl.player.player_moves++;
			}
			event_tracker(global, *p);
		}
	}
}

void	move_left(t_global *global)
{
	char	*p;
	size_t	i;
	size_t	j;

	i = global->game_cntl.player.player_position[0];
	j = global->game_cntl.player.player_position[1];
	if (j > 1)
	{
		p = &(global->map.table[i][j - 1]);
		if (*p != '1')
		{
			if (*p != 'E' && *p != 'H')
			{
				if (*p == 'C')
					global->game_cntl.player.current_point++;
				global->map.table[i][j] = '0';
				*p = 'P';
				global->game_cntl.player.player_position[1] -= 1;
				global->game_cntl.player.player_moves++;
			}
			event_tracker(global, *p);
		}
	}
}

void	move_right(t_global *global)
{
	char	*p;
	size_t	i;
	size_t	j;

	i = global->game_cntl.player.player_position[0];
	j = global->game_cntl.player.player_position[1];
	if (j < global->map.width - 2)
	{
		p = &(global->map.table[i][j + 1]);
		if (*p != '1')
		{
			if (*p != 'E' && *p != 'H')
			{
				if (*p == 'C')
					global->game_cntl.player.current_point++;
				global->map.table[i][j] = '0';
				*p = 'P';
				global->game_cntl.player.player_position[1] += 1;
				global->game_cntl.player.player_moves++;
			}
			event_tracker(global, *p);
		}
	}
}
