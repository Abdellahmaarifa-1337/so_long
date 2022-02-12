/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:23:59 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/12 17:29:12 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strdup(const char	*src)
{
	int		i;
	char	*p;

	i = 0;
	p = (char *)(malloc(sizeof(char) * (ft_strlen(src) + 1)));
	if (p == NULL)
		return (NULL);
	while (src[i])
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
