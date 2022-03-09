/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leldiss <leldiss@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:30:14 by leldiss           #+#    #+#             */
/*   Updated: 2022/03/09 01:13:23 by leldiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	line_count(char *file_name)
{
	int		fd;
	int		ret;
	int		linecount;
	char	ch;

	fd = open (file_name, O_RDONLY);
	if (fd < 0)
		return (-1);
	linecount = 1;
	ret = read (fd, &ch, 1);
	if (ret == 0)
		return (-1);
	while (ret > 0)
	{
		if (ch == '\n')
			linecount++;
		if (ret < 0)
			return (-1);
		ret = read (fd, &ch, 1);
	}
	close (fd);
	return (linecount);
}

int	first_line(int fd)
{
	int		ret;
	int		linelength;
	char	ch;

	linelength = 0;
	ret = read (fd, &ch, 1);
	while (ret > 0)
	{
		if (ch == '\n')
			break ;
		linelength++;
		ret = read (fd, &ch, 1);
	}
	return (linelength);
}

int	line_length(char *file_name)
{
	int		fd;
	int		ret;
	int		linelength;
	int		length;
	char	ch;

	fd = open (file_name, O_RDONLY);
	if (fd < 0)
		return (-1);
	linelength = first_line(fd);
	length = 0;
	ret = read (fd, &ch, 1);
	while (ret > 0)
	{
		if (ch == '\n' && linelength != length)
			return (-1);
		length++;
		if (ch == '\n')
			length = 0;
		ret = read (fd, &ch, 1);
	}
	if (linelength != length)
		return (-1);
	close (fd);
	return (linelength);
}

t_root	map_fill(t_root root, char *file_name)
{
	int		fd;
	char	ch;
	int		i;
	int		k;

	fd = open (file_name, O_RDONLY);
	i = 0;
	while (i < root.linecount)
	{
		k = 0;
		while (k < root.linelength)
		{
			read (fd, &ch, 1);
			root.map[i][k] = ch;
			k++;
		}
		read (fd, &ch, 1);
		root.map[i][k] = '\0';
		i++;
	}
	root.map[i] = '\0';
	close (fd);
	return (root);
}

t_root	map_create(char *file_name, t_root root)
{
	char	**map;
	int		i;

	i = 0;
	root.map = (char **) malloc(sizeof(char *) * (root.linecount + 1));
	while (i < root.linecount)
	{
		root.map[i] = (char *) malloc(sizeof(char) * (root.linelength + 1));
		i++;
	}
	root = map_fill(root, file_name);
	valid_map(root);
	return (root);
}
