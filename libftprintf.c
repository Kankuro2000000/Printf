/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 10:31:11 by vtasia            #+#    #+#             */
/*   Updated: 2021/12/29 11:34:50 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_type(const char *format, int *count, va_list ap)
{
	if (*format == 'c')
		ft_type_c(ap, count);
	if (*format == 's')
		ft_type_s(ap, count);
	if (*format == 'd' || *format == 'i')
		ft_type_dec(ap, count);
	if (*format == 'u')
		ft_type_uns_dec(ap, count);
	if (*format == 'x' || *format == 'X')
		ft_type_hex(ap, count, *format);
	if (*format == 'p')
		ft_type_p(ap, count);
	if (*format == '%')
	{
		write(1, "%", 1);
		(*count)++;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	ap;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			ft_check_type(++format, &count, ap);
			format++;
		}
		else
		{
			write(1, format++, 1);
			count++;
		}
	}
	va_end(ap);
	return (count);
}
