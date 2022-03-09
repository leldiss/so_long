/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leldiss <leldiss@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 02:46:06 by leldiss           #+#    #+#             */
/*   Updated: 2022/03/08 18:38:11 by leldiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_player_up(t_root *root, int steps)
{
	if (root->playerx_matrix >= 1 || root->playery_matrix >= 1)
	{
		if (root->map[root->playery_matrix - 1][root->playerx_matrix] != '1')
		{
			special_move(root, -1, 0, -STEP_Y);
			steps++;
			ft_printf("Steps: %d \n", steps);
			if (root->map[root->playery_matrix - 1][root->playerx_matrix]
				== 'E')
				root->e = 1;
			if (root->map[root->playery_matrix - 1][root->playerx_matrix]
				== 'C')
			{
				root->collect_count--;
				root->map[root->playery_matrix - 1][root->playerx_matrix] = '0';
			}
			if (root->map[root->playery_matrix - 1][root->playerx_matrix]
				== 'E' && root->collect_count <= 0)
				end_programm(root);
		root->playery_matrix -= 1;
		root->player_y -= STEP_Y;
		}
	}
	return (steps);
}

int	move_player_down(t_root *root, int steps)
{
	if (root->playerx_matrix >= 1 || root->playery_matrix >= 1)
	{
		if (root->map[root->playery_matrix + 1][root->playerx_matrix] != '1')
		{
			special_move(root, 1, 0, +STEP_Y);
			steps++;
			ft_printf("Steps: %d \n", steps);
			if (root->map[root->playery_matrix + 1][root->playerx_matrix]
				== 'E')
				root->e = 1;
			if (root->map[root->playery_matrix + 1][root->playerx_matrix]
				== 'C')
			{
				root->collect_count--;
				root->map[root->playery_matrix + 1][root->playerx_matrix] = '0';
			}
			if (root->map[root->playery_matrix + 1][root->playerx_matrix]
				== 'E' && root->collect_count <= 0)
				end_programm(root);
			root->playery_matrix += 1;
			root->player_y += STEP_Y;
		}
	}
	return (steps);
}

int	move_player_left(t_root *root, int steps)
{
	if (root->playerx_matrix >= 1 || root->playery_matrix >= 1)
	{
		if (root->map[root->playery_matrix][root->playerx_matrix - 1] != '1')
		{
			special_move(root, 0, -1, -STEP_X);
			steps++;
			ft_printf("Steps: %d \n", steps);
			if (root->map[root->playery_matrix][root->playerx_matrix - 1]
				== 'E')
				root->e = 1;
			if (root->map[root->playery_matrix][root->playerx_matrix - 1]
				== 'C')
			{
				root->collect_count--;
				root->map[root->playery_matrix][root->playerx_matrix - 1] = '0';
			}
			if (root->map[root->playery_matrix][root->playerx_matrix - 1]
				== 'E' && root->collect_count <= 0)
				end_programm(root);
			root->playerx_matrix -= 1;
			root->player_x -= STEP_X;
		}
	}
	return (steps);
}

int	move_player_right(t_root *root, int steps)
{
	if (root->playerx_matrix >= 1 || root->playery_matrix >= 1)
	{
		if (root->map[root->playery_matrix][root->playerx_matrix + 1] != '1')
		{
			special_move(root, 0, 1, STEP_X);
			steps++;
			ft_printf("Steps: %d \n", steps);
			if (root->map[root->playery_matrix][root->playerx_matrix + 1]
				== 'E')
				root->e = 1;
			if (root->map[root->playery_matrix][root->playerx_matrix + 1]
				== 'C')
			{
				root->collect_count--;
				root->map[root->playery_matrix][root->playerx_matrix + 1] = '0';
			}
			if (root->map[root->playery_matrix][root->playerx_matrix + 1]
				== 'E' && root->collect_count <= 0)
				end_programm(root);
			root->playerx_matrix += 1;
			root->player_x += STEP_X;
		}
	}
	return (steps);
}

int	special_move(t_root *root, int matrix_y, int matrix_x, int step)
{
	if (root->e == 0)
		mlx_put_image_to_window(root->connection, root->window,
			root->floor, root->player_x, root->player_y);
	if (root->e == 1)
	{
		mlx_put_image_to_window(root->connection, root->window,
			root->door, root->player_x, root->player_y);
		root->e = 0;
	}
	if (matrix_x == 0)
		mlx_put_image_to_window(root->connection, root->window,
			root->player, root->player_x, root->player_y + step);
	else if (matrix_y == 0)
		mlx_put_image_to_window(root->connection, root->window,
			root->player, root->player_x + step, root->player_y);
}
