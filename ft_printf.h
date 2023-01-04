/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 10:41:22 by vtasia            #+#    #+#             */
/*   Updated: 2021/12/29 10:41:25 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_check_type(const char *format, int *count, va_list ap);
int		ft_printf(const char *format, ...);
void	ft_convert_hex(unsigned long long int n, int *count, char reg);
void	ft_type_hex(va_list ap, int *count, char reg);
void	ft_type_p(va_list ap, int *count);
void	ft_putnbr_u(unsigned int num);
int		ft_numlen_u(unsigned int num);
void	ft_type_uns_dec(va_list ap, int *count);
void	ft_putnbr(int num);
int		ft_numlen(int num);
void	ft_type_dec(va_list ap, int *count);
void	ft_putchar(char c);
void	ft_type_c(va_list ap, int *count);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
void	ft_type_s(va_list ap, int *count);

#endif
