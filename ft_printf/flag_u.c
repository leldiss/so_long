/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leldiss <leldiss@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:10:04 by leldiss           #+#    #+#             */
/*   Updated: 2022/03/08 17:40:22 by leldiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_uns_count(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_fill_uns_itoa(char *s, unsigned int n, int len)
{
	s[len] = '\0';
	len--;
	if (n > 0)
	{
		while (len > -1)
		{
			s[len] = n % 10 + 48;
			n = n / 10;
			len--;
		}
	}
	else
	{
		while (len > -1)
		{
			s[len] = (n % 10) * (-1) + 48;
			n = n / 10;
			len--;
		}
	}
	return (s);
}

char	*ft_itoa_uns(unsigned int n)
{
	int		len;
	char	*s;

	len = ft_uns_count(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	s = ft_fill_uns_itoa(s, n, len);
	return (s);
}

int	ft_printunsigned(t_check_flag *flag, int i)
{
	char			*s;
	unsigned int	n;

	n = va_arg(flag->arg, unsigned int);
	s = ft_itoa_uns(n);
	if (!s)
		return (-1);
	flag->len += write(1, s, ft_strlen(s));
	free(s);
	return (i + 1);
}
