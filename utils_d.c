/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 14:38:30 by vtasia            #+#    #+#             */
/*   Updated: 2021/12/29 14:38:32 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int num)
{
	if (num == -2147483648)
		ft_putstr("-2147483648");
	else if (num < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-num);
	}
	else if (num > 9)
	{
		ft_putnbr(num / 10);
		ft_putchar(num % 10 + '0');
	}
	else
		ft_putchar(num + '0');
}

int	ft_numlen(int num)
{
	int	len;

	len = 0;
	if (num == -2147483648)
		return (11);
	else if (num == 0)
		return (1);
	if (num < 0)
		len++;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

void	ft_type_dec(va_list ap, int *count)
{
	int	num;

	num = va_arg(ap, int);
	ft_putnbr(num);
	(*count) += ft_numlen(num);
}
