/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_it_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrechai <anrechai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 22:24:58 by anrechai          #+#    #+#             */
/*   Updated: 2021/12/17 00:37:08 by anrechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_size_hexa(unsigned long long int decimal_number, char *base_to)
{
	unsigned long long int	str_size;
	unsigned long long int	max;
	unsigned long long int	base_to_size;

	base_to_size = ft_strlen(base_to);
	max = 1;
	str_size = 0;
	if (decimal_number <= 0)
	{
		str_size++;
		decimal_number *= -1;
	}
	while (max <= decimal_number)
	{
		if (max == 0)
			return ((int)str_size);
		max = max * base_to_size;
		str_size++;
	}
	return ((int)str_size);
}

void	ft_putnbr_hexa(unsigned long long x)
{
	char	*base;

	base = "0123456789abcdef";
	if (x > 15)
	{
		ft_putnbr_hexa(x / 16);
		ft_putnbr_hexa(x % 16);
	}
	else
		ft_putchar(base[x]);
}

int	ft_print_u(va_list params)
{
	unsigned int	nb;
	int				i;

	nb = va_arg(params, unsigned int);
	i = ft_size(nb, "0123456789");
	ft_putnbr(nb);
	return (i);
}

int	ft_print_x(va_list params)
{
	unsigned int	i;
	int				j;

	i = va_arg(params, unsigned int);
	j = ft_size(i, "0123456789abcdef");
	ft_putnbr_hexa(i);
	return (j);
}

int	ft_print_xx(va_list params)
{
	unsigned int	i;
	int				j;

	i = va_arg(params, unsigned int);
	j = ft_size(i, "0123456789abcdef");
	ft_putnbr_hexa_maj(i);
	return (j);
}
