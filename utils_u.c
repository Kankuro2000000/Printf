/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 14:38:37 by vtasia            #+#    #+#             */
/*   Updated: 2021/12/29 14:38:38 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_u(unsigned int num)
{
	if (num > 9)
	{
		ft_putnbr_u(num / 10);
		ft_putchar(num % 10 + '0');
	}
	else
		ft_putchar(num + '0');
}

int	ft_numlen_u(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

void	ft_type_uns_dec(va_list ap, int *count)
{
	unsigned int	num;

	num = va_arg(ap, unsigned int);
	ft_putnbr_u(num);
	(*count) += ft_numlen_u(num);
}
