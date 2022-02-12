/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 21:42:11 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/13 00:37:30 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	load_assets(t_global	*global)
{
	int	dump[2];

	global->assets = (t_assets *)malloc(sizeof(t_assets));
	if (!global->assets)
		throw_error(0, global);
	global->assets->exit_game[0] = mlx_xpm_file_to_image(global->game_cntl->mlx,
		"src/img/exit_1.xpm", &dump[0], &dump[1]);
	global->assets->exit_game[1] = mlx_xpm_file_to_image(global->game_cntl->mlx,
		"src/img/exit_2.xpm", &dump[0], &dump[1]);
	global->assets->exit_game[2] = mlx_xpm_file_to_image(global->game_cntl->mlx,
		"src/img/exit_3.xpm", &dump[0], &dump[1]);
	global->assets->exit_game[3] = mlx_xpm_file_to_image(global->game_cntl->mlx,
		"src/img/exit_4.xpm", &dump[0], &dump[1]);
	global->assets->exit_game[4] = mlx_xpm_file_to_image(global->game_cntl->mlx,
		"src/img/exit_5.xpm", &dump[0], &dump[1]);
	global->assets->exit_game[5] = mlx_xpm_file_to_image(global->game_cntl->mlx,
		"src/img/exit_6.xpm", &dump[0], &dump[1]);
	global->assets->exit_game[6] = mlx_xpm_file_to_image(global->game_cntl->mlx,
		"src/img/exit_7.xpm", &dump[0], &dump[1]);
	global->assets->collectable = mlx_xpm_file_to_image(global->game_cntl->mlx,
		"src/img/collectable.xpm", &dump[0], &dump[1]);
	global->assets->player = mlx_xpm_file_to_image(global->game_cntl->mlx,
		"src/img/player.xpm", &dump[0], &dump[1]);
	global->assets->enemy = mlx_xpm_file_to_image(global->game_cntl->mlx,
		"src/img/enemy.xpm", &dump[0], &dump[1]);
	global->assets->wall = mlx_xpm_file_to_image(global->game_cntl->mlx,
		"src/img/wall.xpm", &dump[0], &dump[1]);
	global->assets->space = mlx_xpm_file_to_image(global->game_cntl->mlx,
		"src/img/space.xpm", &dump[0], &dump[1]);
	global->assets->win_game = mlx_xpm_file_to_image(global->game_cntl->mlx,
		"src/img/win_img.xpm", &dump[0], &dump[1]);
	global->assets->lose_image= mlx_xpm_file_to_image(global->game_cntl->mlx,
		"src/img/lose_img.xpm", &dump[0], &dump[1]);
}
