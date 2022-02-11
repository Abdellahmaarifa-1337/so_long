/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 22:10:53 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/11 00:24:22 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_img(t_global *global, char c)
{
	mlx_put_image_to_window(global->mlx, global->win,
		global->background_img, global->position[1], global->position[0]);
	if (c == '1')
		mlx_put_image_to_window(global->mlx, global->win,
			global->wall_img, global->position[1], global->position[0]);
	else if (c == 'P')
		mlx_put_image_to_window(global->mlx, global->win,
			global->player_img, global->position[1], global->position[0]);
	else if (c == 'E')
		mlx_put_image_to_window(global->mlx, global->win,
			global->holes_img[global->img_nb], global->position[1], global->position[0]);
	else if (c == 'C')
		mlx_put_image_to_window(global->mlx, global->win,
			global->leave_img, global->position[1], global->position[0]);
	else if (c == 'H')
		mlx_put_image_to_window(global->mlx, global->win,
			global->hook_img, global->position[1], global->position[0]);
}

void ft_slip(void)
{
	int m = 0;
	while (m < 100000000)
		m++;
}

// void	move_hooks(t_global **global)
// {
// 	size_t	i;
// 	size_t	j;
// 	size_t	position[2];
// 	i = 0;
// 	(*global)->frame = 0;
// 	position[0] = 100000;
// 	position[1] = 100000;
// 	while (i < (*global)->map->height)
// 	{
// 		j = 0;
// 		while (j < (*global)->map->width)
// 		{
// 			if (position[0] == i && position [1] == j)
// 			{
// 				j++;
// 				continue;
// 			}
// 			if ((*global)->map->line[i][j] == 'H')
// 			{
// 				if ((*global)->hook_move[i][j] == 0)
// 				{
// 					if (i + 1 < (*global)->map->height 
// 					&& ((*global)->map->line[i + 1][j] == '0'
// 					|| (*global)->map->line[i + 1][j] == 'P'))
// 					{
// 						if ((*global)->map->line[i + 1][j] == 'P')
// 						{
// 							// game over
// 							mlx_clear_window( (*global)->mlx, (*global)->win);
// 							printf("game over!\n");
// 							if ((*global)->game_on == 1)
// 								(*global)->game_on = -1;
// 						}
// 						(*global)->map->line[i][j] = '0';
// 						(*global)->map->line[i + 1][j] = 'H';
// 						position[0] = i +1;
// 						position[1] = j;
// 						(*global)->hook_move[i + 1][j] = 0;
// 					}
// 				}
// 				else if ((*global)->hook_move[i][j] == 1)
// 				{
// 					if (i - 1 > 0 
// 					&& ((*global)->map->line[i - 1][j] == '0'
// 					|| (*global)->map->line[i - 1][j] == 'P'))
// 					{
// 						if ((*global)->map->line[i - 1][j] == 'P')
// 						{
// 							// game over
// 							mlx_clear_window( (*global)->mlx, (*global)->win);
// 							printf("game over!\n");
// 							if ((*global)->game_on == 1)
// 								(*global)->game_on = -1;
// 						}
// 						(*global)->map->line[i][j] = '0';
// 						(*global)->map->line[i - 1][j] = 'H';
// 						position[0] = i + 1;
// 						position[1] = j;
// 						(*global)->hook_move[i - 1][j] = 1;
					
// 					}
// 				}
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }
// /*
//  0 -> move down
//  1 -> move up
//  2 -> don't move
// */
// void calc_direction_hooks(t_global *global)
// {
// 	size_t	i;
// 	size_t	j;
// 	int		down;
// 	int		up;

// 	i = 0;
// 	while (i < global->map->height)
// 	{
// 		j = 0;
// 		while (j < global->map->width)
// 		{
// 			if (global->map->line[i][j] == 'H')
// 			{
// 				down = (i + 1 < global->map->height 
// 						&& (global->map->line[i + 1][j] == '0' ||
// 						global->map->line[i + 1][j] == 'P'));
// 				up = (i > 1 
// 						&& (global->map->line[i - 1][j] == '0' ||
// 						 global->map->line[i - 1][j] == 'P'));

// 				if (global->hook_move[i][j] == -1
// 					|| (global->hook_move[i][j] == 0 && !down)
// 					|| (global->hook_move[i][j] == 1 && !up))
// 				{
// 					if (down)
// 						global->hook_move[i][j] = 0;
// 					else if (up)
// 						global->hook_move[i][j] = 1;
// 				}
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }
/*

 last direction:
	-1 : calc direction defaults;
	down (0): if down posible do noting else calculate
	up (1) : if up possible do noting else calculate
	(2) : do nothing.

*/

void move_hooks(t_global *global)
{
	int i;
	i = 0;
	size_t x;
	size_t y;


	while (i < global->hooks_size)
	{
		x = (global->hooks[i])->x;
		y = (global->hooks[i])->y;
		printf("x %zu y %zu and d %d\n", x, y,(global->hooks[i])->direction);
		if ((global->hooks[i])->direction == 0)
		{
			if (global->map->line[x + 1][y] == 'P')
			{
				mlx_clear_window( (global)->mlx, (global)->win);
				if ((global)->game_on == 1)
					(global)->game_on = -1;
			}
			// move down
			global->map->line[x][y] = '0';
			global->map->line[x + 1][y] = 'H';
			(global->hooks[i])->x += 1;
			x++;
			// updte x and y and direction
			if (x + 2 < global->map->height 
 						&& (global->map->line[x + 1][y] == '0' ||
 						global->map->line[x + 1][y] == 'P'))
			{
				(global->hooks[i])->direction = 0;
			}else if (x > 1 
					&& (global->map->line[x - 1][y] == '0' ||
						global->map->line[x - 1][y] == 'P'))
			{
				(global->hooks[i])->direction = 1;
			}
		}
		else if ((global->hooks[i])->direction == 1)
		{
			if (global->map->line[x - 1][y] == 'P')
			{
				mlx_clear_window( (global)->mlx, (global)->win);
				if ((global)->game_on == 1)
					(global)->game_on = -1;
			}
			global->map->line[x][y] = '0';
			global->map->line[x - 1][y] = 'H';
			(global->hooks[i])->x -= 1;
			x--;
			if (x > 1 
					&& (global->map->line[x - 1][y] == '0' ||
						global->map->line[x - 1][y] == 'P'))
			{
				(global->hooks[i])->direction = 1;
			}
			else if (x + 2 < global->map->height 
 						&& (global->map->line[x + 1][y] == '0' ||
 						global->map->line[x + 1][y] == 'P'))
			{
				(global->hooks[i])->direction = 0;
			}
		}
		else if ((global->hooks[i])->direction == 2)
		{
			if (x > 1 
				&& (global->map->line[x - 1][y] == '0' ||
				global->map->line[x - 1][y] == 'P'))
			{
				(global->hooks[i])->direction = 1;
			}
			else if (x + 2 < global->map->height 
				&& (global->map->line[x + 1][y] == '0' ||
				global->map->line[x + 1][y] == 'P'))
			{
				(global->hooks[i])->direction = 0;
			}
		}
		i++;
	}
	global->frame = 0;
	printf("I was here\n");
}

int	render(t_global *global)
{
	size_t		i;
	size_t		j;
	//char		*s;
	//printf("global->game_on %d\n", global->game_on);
	if (global->game_on == 1)
	{
		// counter !
		//s = ft_itoa(global->moves_count);
	
		if (global->frame == 40)
		{
			
			printf("Dkhelti?\n");
			move_hooks(global);

			//calc_direction_hooks(global);
		}else if (global->frame == 20 || global->frame == 40)
		{
		global->img_nb++;

		}

		mlx_clear_window (global->mlx, global->win);
		i = 0;
		if (global->img_nb > 6)
			global->img_nb = 0;
		while (i < (global->map)->height)
		{
			j = 0;
			while (j < (global->map)->width)
			{
				global->position[0] = i * 60;
				global->position[1] = j * 60;
				put_img(global, global->map->line[i][j]);
				j++;
			}
			i++;
		}
		mlx_string_put(global->mlx,
						global->win,
						10,
						10,
						0x000000, "moves: ");
		mlx_string_put(global->mlx,
						global->win,
						80,
						10,
						0x000000, ft_itoa(global->moves_count));
		//ft_slip();
		global->frame++;
	}
	else if (global->game_on == -1){
		mlx_clear_window(global->mlx, global->win);
		mlx_string_put(global->mlx,
						global->win,
						(global->map->width * 60) / 2,
						(global->map->height * 60) / 2,
						0xFFFFFF, "you lose!");
	}
	else if (global->game_on == 0)
	{
	
		mlx_clear_window(global->mlx, global->win);
		mlx_string_put(global->mlx,
						global->win,
						(global->map->width * 60) / 2,
						(global->map->height * 60) / 2,
						0xFFFFFF, "you win!");
	}
	global->frame++;

	//free(positon);
	return (1);
}

	// while (1)
	// {global->holes[global->img_nb]
	// 	put_img(global->mlx, global->win, "src/img/hole1.xpm", player);
	// 	 sleep(1);
	// 	put_img(global->mlx, global->win, "src/img/hole2.xpm", player);
	// 	 sleep(1);
	// 	put_img(global->mlx, global->win, "src/img/hole3.xpm", player);
	// 	 sleep(1);
	// 	put_img(global->mlx, global->win, "src/img/hole4.xpm", player);
	// 	sleep(1);
	// 	put_img(global->mlx, global->win, "src/img/hole5.xpm", player);
	// 	 sleep(1);
	// 	put_img(global->mlx, global->win, "src/img/hole6.xpm", player);
	// 	 sleep(1);
	// 	put_img(global->mlx, global->win, "src/img/hole7.xpm", player);
	// 	 sleep(1);
	// }