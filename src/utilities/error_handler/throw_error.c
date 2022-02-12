/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:51:37 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/12 23:00:22 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	print_error(int error_code)
{
	char	*errors[18];

	errors[0] = "Not enough space\n";
	errors[1] = "You must provide a map and only the map!\n";
	errors[2] = "Please provid a valid (.ber) map\n";
	errors[3] = "The file doesn't exist.\n";
	errors[4] = "The file is empty.\n";
	errors[5] = "The map must be srounded by the walls.\n";
	errors[6] = "only these characters are allowed : 0 1 C E P H\n";
	errors[7] = "The map file should end up with a wall\n";
	errors[8] = "Missign one of these  characters : C E P.\n";
	errors[9] = "There is more one start position\n";
	ft_putstr(errors[error_code]);
}

int	ft_close(int keycode)
{
	(void) keycode;
	exit(0);
	return (1);
}

void	throw_error(int error_code, t_global *global)
{
	(void) global;
	print_error(error_code);
	exit(1);
}
