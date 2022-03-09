/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_cs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leldiss <leldiss@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:46:40 by leldiss           #+#    #+#             */
/*   Updated: 2022/03/08 17:40:15 by leldiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_printchar(t_check_flag *flag, int i)
{
	char	c;

	c = (char)va_arg(flag->arg, int);
	flag->len += write(1, &c, 1);
	return (i + 1);
}

int	ft_printstr(t_check_flag *flag, int i)
{
	char	*s;

	s = va_arg(flag->arg, char *);
	if (!s)
		flag->len += write(1, "(null)", 6);
	else
		flag->len += write(1, s, ft_strlen(s));
	return (i + 1);
}
