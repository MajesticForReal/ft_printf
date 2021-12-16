/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_it.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrechai <anrechai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:27:13 by anrechai          #+#    #+#             */
/*   Updated: 2021/12/17 00:36:42 by anrechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hexa_maj(unsigned long long x)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (x > 15)
	{
		ft_putnbr_hexa_maj(x / 16);
		ft_putnbr_hexa_maj(x % 16);
	}
	else
		ft_putchar(base[x]);
}

int	ft_print_c(va_list params)
{
	int	c;

	c = va_arg(params, int);
	write(1, &c, 1);
	return (1);
}

int	ft_print_s(va_list params)
{
	const char	*str;
	int			i;

	str = va_arg(params, const char *);
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_print_p(va_list params, int j)
{
	unsigned long long	nb;
	int					i;

	nb = va_arg(params, unsigned long long int);
	i = ft_size_hexa(nb, "0123456789abcdef");
	if (j == 1)
	{
		ft_putchar('0');
		ft_putchar('x');
	}
	ft_putnbr_hexa(nb);
	return (i + 2);
}

int	ft_print_d(va_list params)
{
	long int	nb;
	int			i;

	nb = va_arg(params, int);
	i = ft_size(nb, "0123456789");
	ft_putnbr(nb);
	return (i);
}
