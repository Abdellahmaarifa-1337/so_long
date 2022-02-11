/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:19:52 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/10 19:02:06 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_only_char(char *s, char *chars, t_map **map)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (!ft_strchr(chars, s[i]))
			break ;
		i++;
	}
	if (s[i])
		return (0);
	if (s[0] != '1' || s[i - 1] != '1')
		throw_err("The map should be srounded by walls", map);
	return (1);
}

char	*cut_new_line(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	if (s[i - 1] == '\n')
		s[i - 1] = '\0';
	return (s);
}

int	map_chr(t_map *map, char c)
{
	size_t	i;
	size_t	j;
	int		k;

	k = 0;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->line[i][j])
		{
			if (map->line[i][j] == c)
				k++;
			j++;
		}
		i++;
	}
	if (c == 'P' && k > 1)
		throw_err("There is more one start position", &map);
	return (k);
}



int	calc_lines(char *path, t_map **map)
{
	int		fd;
	int		i;
	char	*s;
	char	c;

	fd = open(path, O_RDONLY);
	s = cut_new_line(get_next_line(fd, BUFFER_SIZE));
	if (!s)
		throw_err("This file is empty or doesn't exist", map);
	if (!is_only_char(s, "1", map))
		throw_err("The map must be closed by walls", map);
	(*map)->width = ft_strlen(s);
	i = 1;
	while (s)
	{
		free(s);
		s = get_next_line(fd, BUFFER_SIZE);
		if (last_char(s))
			c = last_char(s);
		s = cut_new_line(s);
		if (!s)
			break ;
		if (!is_only_char(s, "01CEPH", map) || ft_strlen(s) != (*map)->width)
			throw_err("only these characters are allowed : 0 1 C E P H", map);
		i++;
	}
	if (c == '\n')
		throw_err("bad map", map);
	(*map)->height = i;
	close(fd);
	return (i);
}

void	map_parsser(char *path, t_map **map)
{
	int		fd;
	char	*line;
	int		i;
	calc_lines(path, map);

	fd = open(path, O_RDONLY);
	line = cut_new_line(get_next_line(fd, BUFFER_SIZE));
	(*map)->line = (char **)malloc(sizeof(char *) * (*map)->height);
	(*map)->line[0] = line;
	i = 1;
	while (line)
	{
		line = cut_new_line(get_next_line(fd, BUFFER_SIZE));
		if (!line)
			break ;
		(*map)->line[i] = line;
		i++;
	}
	if (!is_only_char((*map)->line[(*map)->height - 1], "1", map))
		throw_err("The map must be closed by walls", map);
	if (!map_chr((*map), 'C') || !map_chr((*map), 'E') || !map_chr((*map), 'P'))
		throw_err("Missign one of these  characters : C E P.", map);
	close(fd);
}
