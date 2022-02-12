/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:41:59 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/13 00:17:24 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	print_map(t_global *global)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < global->map->height)
	{
		j = 0;
		while (j < global->map->width)
		{
			printf("%c ", global->map->table[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	key_hook(int keycode, t_global *global)
{
	if (keycode == 13)
		move_up(global);
	else if (keycode == 1)
		move_down(global);
	else if (keycode == 0)
		move_left(global);
	else if (keycode == 2)
		move_right(global);
	else if (keycode == 53)
		exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_global	global;

	if (ac != 2)
		throw_error(1, &global);
	map_parser(av[1], &global);
	global.game_cntl = (t_game_cntl *)malloc(sizeof(t_game_cntl));
	if (!global.game_cntl)
		throw_error(0, &global);
	global.game_cntl->mlx = mlx_init();
	global.game_cntl->win = mlx_new_window(global.game_cntl->mlx,
			global.map->width * 60, (global.map->height + 1) * 60, "SpaceUP");
	load_assets(&global);
	init_game(&global);
	mlx_key_hook(global.game_cntl->win, key_hook, &global);
	mlx_loop_hook(global.game_cntl->mlx, &render, &global);
	mlx_hook(global.game_cntl->win, 17, 1L << 5, ft_close, &global);
	mlx_loop(global.game_cntl->mlx);
}
