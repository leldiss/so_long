/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leldiss <leldiss@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:44:28 by leldiss           #+#    #+#             */
/*   Updated: 2022/03/09 01:13:30 by leldiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	isber(char *file_name)
{
	int				len;

	len = ft_strlen(file_name);
	if (file_name == 0)
		return (0);
	if (len < 5)
		return (0);
	if (ft_strcmp(file_name + len - 4, ".ber") != 0)
		return (0);
	return (1);
}

int	valid_file(int argc, char *file_name)
{
	if (argc == 1)
	{
		error("no args");
		exit(0);
	}
	if (argc > 2)
		ft_printf("only the first file would be used\n");
	if (!isber(file_name))
	{
		error("map should be a .ber file");
		exit(0);
	}
	return (1);
}
