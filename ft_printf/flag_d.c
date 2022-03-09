/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leldiss <leldiss@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:50:23 by leldiss           #+#    #+#             */
/*   Updated: 2022/03/09 01:42:02 by leldiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

int	count_digits(int n)
{
	int	k;

	k = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
		k = 1;
	while (n != 0)
	{
		n = n / 10;
		k++;
	}
	return (k);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		c;
	int		i;

	c = count_digits(n);
	i = c - 1;
	str = (char *)malloc(sizeof(char) * (c + 1));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	else if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[i] = ft_abs(n % 10) + '0';
		n /= 10;
		i--;
	}
	str[c] = '\0';
	return (str);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_printdigit(t_check_flag *flag, int i)
{
	char	*str;
	int		n;

	n = va_arg(flag->arg, int);
	str = ft_itoa(n);
	if (!str)
		return (-1);
	flag->len += write(1, str, ft_strlen(str));
	free(str);
	return (i + 1);
}
/* duyrka */