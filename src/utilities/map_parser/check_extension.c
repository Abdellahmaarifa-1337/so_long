/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:04:47 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/12 17:05:13 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_extension(char *map_file, char *ext)
{
	int	len_map_file;
	int	len_ext;

	len_map_file = ft_strlen(map_file);
	len_ext = ft_strlen(ext);
	if (len_map_file <= len_ext)
		return (0);
	map_file += (len_map_file - len_ext);
	while (*(map_file++) == *(ext++) && *ext)
		;
	if (*map_file)
		return (0);
	return (1);
}
