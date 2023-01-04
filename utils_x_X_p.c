/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_x_X_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 14:38:43 by vtasia            #+#    #+#             */
/*   Updated: 2021/12/29 14:38:45 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_hex(unsigned long long int n, int *count, char reg)
{
	if (n >= 16)
	{
		ft_convert_hex(n / 16, count, reg);
		n %= 16;
	}
	if (n > 9 && n < 16)
	{
		if (reg == 'x')
			ft_putchar((n % 10) + 'a');
		else
			ft_putchar((n % 10) + 'A');
	}
	else
		ft_putchar(n + '0');
	(*count)++;
}

void	ft_type_p(va_list ap, int *count)
{
	unsigned long long int	value;

	value = va_arg(ap, unsigned long long int);
	write(1, "0x", 2);
	*count += 2;
	ft_convert_hex(value, count, 'x');
}

void	ft_type_hex(va_list ap, int *count, char reg)
{
	unsigned int	value;

	value = va_arg(ap, unsigned int);
	ft_convert_hex(value, count, reg);
}
