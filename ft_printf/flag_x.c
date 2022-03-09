/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leldiss <leldiss@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:08:50 by leldiss           #+#    #+#             */
/*   Updated: 2022/03/08 17:40:25 by leldiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_itoa_small_hex(unsigned int x)
{
	char			*s;
	int				len;

	len = ft_len_hex(x);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	s[len] = 0;
	len--;
	while (len >= 0)
	{
		s[len] = ft_small_symbol(x % 16);
		x = x / 16;
		len--;
	}
	return (s);
}

int	ft_printsmallhex(t_check_flag *flag, int i)
{
	unsigned int	x;
	char			*s;

	x = va_arg(flag->arg, unsigned int);
	if (x == 0)
		flag->len += write(1, "0", 1);
	else
	{
		s = ft_itoa_small_hex(x);
		if (!s)
			return (-1);
		flag->len += write(1, s, ft_strlen(s));
		free(s);
	}
	return (i + 1);
}

char	*ft_itoa_big_hex(unsigned int x)
{
	char			*s;
	int				len;

	len = ft_len_hex(x);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	s[len] = 0;
	len--;
	while (len >= 0)
	{
		s[len] = ft_big_symbol(x % 16);
		x = x / 16;
		len--;
	}
	return (s);
}

int	ft_printbighex(t_check_flag *flag, int i)
{
	unsigned int	x;
	char			*s;

	x = va_arg(flag->arg, unsigned int);
	if (x == 0)
		flag->len += write(1, "0", 1);
	else
	{
		s = ft_itoa_big_hex(x);
		if (!s)
			return (-1);
		flag->len += write(1, s, ft_strlen(s));
		free(s);
	}
	return (i + 1);
}
