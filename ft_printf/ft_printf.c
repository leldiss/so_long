/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leldiss <leldiss@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:49:36 by leldiss           #+#    #+#             */
/*   Updated: 2022/01/12 10:49:36 by leldiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	parsflag(const char *format, t_check_flag *flag, int i)
{
	if (format[i] == '%')
	{
		flag->len += write(1, "%", 1);
		return (i + 1);
	}
	else if (format[i] == 'c')
		return (ft_printchar(flag, i));
	else if (format[i] == 's')
		return (ft_printstr(flag, i));
	else if (format[i] == 'p')
		return (ft_printaddress(flag, i));
	else if (format[i] == 'd' || format[i] == 'i')
		return (ft_printdigit(flag, i));
	else if (format[i] == 'u')
		return (ft_printunsigned(flag, i));
	else if (format[i] == 'x')
		return (ft_printsmallhex(flag, i));
	else if (format[i] == 'X')
		return (ft_printbighex(flag, i));
	else
		return (-1);
}

int	print(const char *format, t_check_flag *flag)
{
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			i = parsflag(format, flag, i + 1);
		else
			flag->len += write(1, &format[i++], 1);
		if (i == -1)
			return (-1);
	}
	return (flag->len);
}

int	ft_printf(const char *format, ...)
{
	t_check_flag	*flag;
	int				len;

	flag = malloc(sizeof(t_check_flag));
	if (!flag)
		return (-1);
	flag->len = 0;
	va_start (flag->arg, format);
	len = print(format, flag);
	va_end (flag->arg);
	free(flag);
	return (len);
}
