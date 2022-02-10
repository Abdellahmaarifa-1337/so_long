/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:39:49 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/10 13:10:23 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	event_tracker(t_global *global, char c)
{
	if (c == 'H' && global->game_on == 1)
			global->game_on = -1;
	else if (global->current_point == global->total_point
				&& c == 'E' && global->game_on == 1)
				global->game_on = 0;
}

void	move_down(t_global *global)
{
	char		*p;
	size_t		i;
	size_t		j;

	i = global->player_position[0];
	j = global->player_position[1];
	if (i < global->map->height - 2)
	{
		p = &(global->map->line[i + 1][j]);
		if (*p != '1')
		{
			if (*p != 'E' && *p != 'H')
			{
				if (*p == 'C')
					global->current_point++;
				global->map->line[i][j] = '0';
				*p = 'P';
				global->player_position[0] += 1;
				global->moves_count++;
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

	i = global->player_position[0];
	j = global->player_position[1];
	if (i > 1)
	{
		p = &(global->map->line[i - 1][j]);
		if (*p != '1')
		{
			if (*p != 'E'  && *p != 'H')
			{
				if (*p == 'C')
					global->current_point++;
				global->map->line[i][j] = '0';
				*p = 'P';
				global->player_position[0] -= 1;
				global->moves_count++;
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

	i = global->player_position[0];
	j = global->player_position[1];
	if (j > 1)
	{
		p = &(global->map->line[i][j - 1]);
		if (*p != '1')
		{
			if (*p != 'E'  && *p != 'H')
			{
				if (*p == 'C')
					global->current_point++;
				global->map->line[i][j] = '0';
				*p = 'P';
				global->player_position[1] -= 1;
				global->moves_count++;
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

	i = global->player_position[0];
	j = global->player_position[1];
	if (j < global->map->width - 2)
	{
		p = &(global->map->line[i][j + 1]);
		if (*p != '1')
		{
			if (*p != 'E'  && *p != 'H')
			{
				if (*p == 'C')
					global->current_point++;
				global->map->line[i][j] = '0';
				*p = 'P';
				global->player_position[1] += 1;
				global->moves_count++;
			}
			event_tracker(global, *p);
		}
	}
}
