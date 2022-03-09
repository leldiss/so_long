/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leldiss <leldiss@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:45:42 by leldiss           #+#    #+#             */
/*   Updated: 2022/03/09 01:13:21 by leldiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	error_message(int vihod, int collect, int player)
{
	if (vihod == 0 && collect == 0 && player == 0)
		return (error("There must be at least one collectible, exit, player"));
	else if (vihod == 0 && collect == 0)
		return (error("There must be at least one collectible and one exit"));
	else if (vihod == 0)
		return (error("There must be at least one exit"));
	else if (collect == 0)
		return (error("There must be at least one collectible"));
	else if (player == 0)
		return (error("There must be at least one start position"));
	else if (player > 1)
		return (error("There must be one start position"));
	return (1);
}

int	valid_char(t_root root, int y, int x)
{
	static int	vihod = 0;
	static int	collect = 0;
	static int	player = 0;
	char		c;
	int			flag;

	flag = 1;
	c = root.map[y][x];
	if (c == '1' || c == '0' || c == 'E' || c == 'C' || c == 'P')
	{
		if (c == 'E')
			vihod++;
		if (c == 'C')
			collect++;
		if (c == 'P')
			player++;
		if (y == root.linecount - 2 && x == root.linelength - 2)
			flag = error_message(vihod, collect, player);
		return (flag);
	}
	return (-1);
}

int	valid_border(char c)
{
	if (c != '1')
		return (error("The map must be closed/surrounded by walls."));
	return (1);
}

int	valid_map(t_root root)
{
	int	y;
	int	x;

	y = 0;
	while (y < root.linecount)
	{
		x = 0;
		while (x < root.linelength)
		{
			if (y == 0 || y == root.linecount - 1
				|| x == 0 || x == root.linelength - 1)
			{
				if (valid_border(root.map[y][x]) == -1)
					map_not_valid(&root);
			}
			else if (valid_char(root, y, x) == -1)
				map_not_valid(&root);
			x++;
		}
		y++;
	}
	return (1);
}
