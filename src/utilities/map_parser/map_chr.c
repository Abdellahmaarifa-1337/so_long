/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:02:03 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/13 17:05:43 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	map_chr(t_global *global, char c)
{
	size_t	i;
	size_t	j;
	int		k;

	k = 0;
	i = 0;
	while (i < global->map.height)
	{
		j = 0;
		while (global->map.table[i][j])
		{
			if (global->map.table[i][j] == c)
				k++;
			j++;
		}
		i++;
	}
	if (c == 'P' && k > 1)
		throw_error(9, global);
	return (k);
}
