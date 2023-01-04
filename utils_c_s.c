/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utills_c_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 14:38:04 by vtasia            #+#    #+#             */
/*   Updated: 2021/12/29 15:12:57 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_type_c(va_list ap, int *count)
{
	char	c;

	c = va_arg(ap, int);
	ft_putchar(c);
	(*count)++;
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

void	ft_type_s(va_list ap, int *count)
{
	char	*str;

	str = va_arg(ap, char *);
	if (!str)
	{
		ft_putstr("(null)");
		(*count) += 6;
	}
	else
	{
		ft_putstr(str);
		(*count) += ft_strlen(str);
	}
}
