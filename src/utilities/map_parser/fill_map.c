/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:00:53 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/13 18:36:31 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	fill_map(char *map_file, t_global *global)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(map_file, O_RDONLY);
	line = trim_new_line(get_next_line(fd));
	global->map.table[0] = line;
	i = 1;
	while (line)
	{
		line = trim_new_line(get_next_line(fd));
		if (!line)
			break ;
		global->map.table[i] = line;
		i++;
	}
	if (!is_only_char(global->map.table[global->map.height - 1], "1"))
		throw_error(5);
	if (!map_chr(global, 'C') || !map_chr(global, 'E') || !map_chr(global, 'P'))
		throw_error(8);
	close(fd);
}
