/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:18:53 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/13 18:36:43 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/*
	The map parser, parse the given map.ber file and parse its lines.
	it exite the programme when :
		- The file name does not have .ber extention.
		- The file doesn't exist.
		- The map dosn't surrounded by the walls
		- The map dosn't contain an exit or a collectible or a starting position.
		- The map is not rectangular.
*/

t_map	*map_parser(char *map_file, t_global *global)
{
	if (!check_extension(map_file, ".ber"))
		throw_error(2);
	count_lines(map_file, global);
	global->map.table = (char **)malloc(sizeof(char *) * global->map.height);
	if (!global->map.table)
		throw_error(0);
	fill_map(map_file, global);
	return (0);
}
