/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrechai <anrechai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 20:04:01 by anrechai          #+#    #+#             */
/*   Updated: 2021/12/16 22:16:02 by anrechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>

size_t	ft_strlen(const char *s);

int		ft_print_s(va_list params);
int		ft_print_d(va_list params);
int		ft_print_c(va_list params);
int		ft_print_p(va_list params, int j);
int		print(va_list params, int i, int k, const char *str);
int		ft_print_u(va_list params);
int		ft_print_x(va_list params);
int		ft_print_xx(va_list params);

void	ft_putstr(const char *str);
void	ft_putchar(char c);
void	ft_putnbr(long int n);
void	ft_putnbr_hexa(unsigned long long x);
void	ft_putnbr_hexa_maj(unsigned long long x);
void	ft_putchar(char c);

int		ft_printf(const char *str, ...);
int		ft_size_hexa(unsigned long long int decimal_number, char *base_to);
int		ft_size(long long int decimal_number, char *base_to);

#endif
