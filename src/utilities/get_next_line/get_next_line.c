/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:21:18 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/12 19:50:39 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	get_nl(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*get_line(char **s)
{
	char	*temp;
	int		j;
	char	*t_s;

	j = get_nl(*s);
	if (j >= 0)
	{
		temp = ft_substr(*s, 0, j + 1);
		t_s = ft_strdup(*s + j + 1);
		free(*s);
		*s = t_s;
		return (temp);
	}
	temp = ft_strdup(*s);
	s[0][0] = '\0';
	return (temp);
}

static void	read_line(int fd, char **buf, char **s, int buffer_size)
{
	int	j;

	while (1)
	{
		j = read(fd, *buf, buffer_size);
		if (j <= 0)
			break ;
		buf[0][j] = '\0';
		*s = ft_strjoin(*s, *buf);
		if (get_nl(*buf) >= 0)
			break ;
	}
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*s;
	int			buffer_size;

	buffer_size = 10;
	if (fd < 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (buffer_size + 1));
	if (!buf)
		return (0);
	if (!s)
		s = ft_strdup("");
	read_line(fd, &buf, &s, buffer_size);
	free(buf);
	if (s && s[0])
		return (get_line(&s));
	if (s)
		free(s);
	s = NULL;
	return (0);
}
