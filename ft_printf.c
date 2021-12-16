/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrechai <anrechai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 20:20:54 by anrechai          #+#    #+#             */
/*   Updated: 2021/12/17 00:38:03 by anrechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_size(long long int decimal_number, char *base_to)
{
	long long int	str_size;
	long long int	max;
	long long int	base_to_size;

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

int	ft_check_str(const char *str, int i)
{
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == 'c')
			return (1);
		else if (str[i] == '%' && str[i + 1] == 's')
			return (2);
		else if (str[i] == '%' && str[i + 1] == 'p')
			return (3);
		else if (str[i] == '%' && str[i + 1] == 'd')
			return (4);
		else if (str[i] == '%' && str[i + 1] == 'i')
			return (5);
		else if (str[i] == '%' && str[i + 1] == 'u')
			return (6);
		else if (str[i] == '%' && str[i + 1] == 'x')
			return (7);
		else if (str[i] == '%' && str[i + 1] == 'X')
			return (8);
		else if (str[i] == '%' && str[i + 1] == '%')
			return (9);
		i++;
	}
	return (0);
}

int	ft_print_before_arg(const char *str, int i)
{
	while (str[i])
	{
		if (str[i] == '%' && (str[i + 1] == 'c' || str[i + 1] == 's'
				|| str[i + 1] == 'p' || str[i + 1] == 'd' || str[i + 1] == 'i'
				|| str[i + 1] == 'u' || str[i + 1] == 'x' || str[i + 1] == 'X'
				|| str[i + 1] == '%'))
		{
			i = i + 2;
			return (i);
		}
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	print(va_list params, int i, int k, const char *str)
{
	if (ft_check_str(str, i - 2) == 1)
		k = k + ft_print_c(params);
	else if (ft_check_str(str, i - 2) == 2)
		k = k + ft_print_s(params);
	else if (ft_check_str(str, i - 2) == 3)
		k = k + ft_print_p(params, 1);
	else if (ft_check_str(str, i - 2) == 4)
		k = k + ft_print_d(params);
	else if (ft_check_str(str, i - 2) == 5)
		k = k + ft_print_d(params);
	else if (ft_check_str(str, i - 2) == 6)
		k = k + ft_print_u(params);
	else if (ft_check_str(str, i - 2) == 7)
		k = k + ft_print_x(params);
	else if (ft_check_str(str, i - 2) == 8)
		k = k + ft_print_xx(params);
	else if (ft_check_str(str, i - 2) == 9)
	{
		ft_putchar('%');
		k++;
	}
	return (k);
}

int	ft_printf(const char *str, ...)
{
	va_list		params;
	int			i;
	int			j;
	int			k;

	va_start(params, str);
	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		i = ft_print_before_arg(str, i);
		if (ft_check_str(str, i - 2) >= 1 && ft_check_str(str, i - 2) <= 9)
			k = print(params, i, k, str);
		else
			j--;
		j++;
	}
	va_end(params);
	return (k + (i - (j * 2)));
}
