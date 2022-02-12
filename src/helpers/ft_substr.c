/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:24:56 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/12 17:25:38 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	if (start >= ft_strlen(s))
	{
		free(s);
		return (ft_strdup(""));
	}
	if (ft_strlen(s) >= len)
		substr = (char *)malloc((len + 1) * sizeof(char));
	else
		substr = (char *)malloc((ft_strlen(s) - start + 1) * sizeof(char));
	if (!substr)
		return (0);
	while (i < len && i < ft_strlen(s))
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[len] = '\0';
	return (substr);
}
