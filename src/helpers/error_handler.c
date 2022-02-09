/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:24:11 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/08 19:46:04 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	throw_err(char *err, t_map **map)
{	
	// if (*map)
	// 	while ((*map)->height--)
	// 		free((*map)->line[(*map)->height]);
	free(*map);
	printf("Error\n%s\n", err);
	exit(1);
}
