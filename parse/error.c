/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leldiss <leldiss@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:49:36 by leldiss           #+#    #+#             */
/*   Updated: 2022/03/09 01:42:56 by leldiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	null_error(char *message)
{
	ft_printf("Error\n%s\n", message);
	exit(0);
}

int	error(char *message)
{
	ft_printf("Error\n%s\n", message);
	return (-1);
}

void	free_map(t_root *root)
{
	int	i;

	i = 0;
	while (root->map[i] != NULL)
	{
		free(root->map[i]);
		i++;
	}
	free(root->map);
}

int	map_not_valid(t_root *root)
{
	if (root-> window != 0)
		mlx_destroy_window(root->connection, root->window);
	if (root->connection != 0)
		mlx_destroy_display(root->connection);
	free(root->connection);
	free_map(root);
	root->map = NULL;
	exit(0);
	return (0);
}

int	end_programm(t_root *root)
{
	if (root->floor != 0)
		mlx_destroy_image(root->connection, root->floor);
	if (root->player != 0)
		mlx_destroy_image(root->connection, root->player);
	if (root->collectible != 0)
		mlx_destroy_image(root->connection, root->collectible);
	if (root->wall != 0)
		mlx_destroy_image(root->connection, root->wall);
	if (root->door != 0)
		mlx_destroy_image(root->connection, root->door);
	if (root-> window != 0)
		mlx_destroy_window(root->connection, root->window);
	if (root->connection != 0)
		mlx_destroy_display(root->connection);
	if (root->connection != 0)
		free(root->connection);
	if (root->map != 0)
		free_map(root);
	exit(0);
	return (0);
}
