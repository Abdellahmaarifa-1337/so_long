/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 19:56:09 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/13 15:51:38 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	count_height(char *line, t_global *global, int fd)
{
	char	c;

	while (line)
	{
		free(line);
		line = get_next_line(fd);
		ft_last_char(line, &c);
		line = trim_new_line(line);
		if (!line)
			break ;
		if (!is_only_char(line, "01CEPH")
			|| ft_strlen(line) != global->map.width)
			throw_error(6, global);
		if (line[0] != '1' || line[global->map.width - 1] != '1')
			throw_error(5, global);
		global->map.height++;
	}
	if (c == '\n')
		throw_error(7, global);
}

void	count_lines(char *map_file, t_global *global)
{
	char	*line;
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		throw_error(3, global);
	line = trim_new_line(get_next_line(fd));
	if (!line)
		throw_error(4, global);
	if (!is_only_char(line, "1"))
		throw_error(5, global);
	global->map.width = ft_strlen(line);
	global->map.height = 1;
	count_height(line, global, fd);
	close(fd);
}
