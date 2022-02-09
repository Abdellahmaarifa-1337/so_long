/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:15:30 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/10 00:05:53 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdlib.h>

int	count_int_char(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		s;
	char	*str;
	long	nb;

	if (n == 0)
		return (ft_strdup("0"));
	s = count_int_char(n);
	str = (char *)malloc(sizeof(char) * (s + 1));
	if (!str)
		return (0);
	str[s] = '\0';
	nb = n;
	if (n < 0)
	{
		str[0] = '-';
		nb *= -1;
	}		
	while (nb > 0)
	{
		str[s - 1] = (nb % 10) + 48;
		nb /= 10;
		s--;
	}
	return (str);
}
