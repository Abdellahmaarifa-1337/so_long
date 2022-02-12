/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_only_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 19:58:06 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/12 19:59:59 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_only_char(char *line, char *chars)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (!ft_strchr(chars, line[i]))
			break ;
		i++;
	}
	if (line[i])
		return (0);
	return (1);
}
