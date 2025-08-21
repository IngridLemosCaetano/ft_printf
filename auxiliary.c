/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilemos-c <ilemos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:32:29 by ilemos-c          #+#    #+#             */
/*   Updated: 2025/08/21 19:24:30 by ilemos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_direction_string(va_list args)
{
	size_t	len;
	char	*str;

	str = va_arg(args, char *);
	if (str)
	{
		len = ft_strlen(str);
		ft_putstr_fd(str, 1);
	}
	else
	{
		len = 6;
		ft_putstr_fd("(null)", 1);
	}
	return (len);
}

size_t	ft_direction_c_(char c, va_list args)
{
	char	v_c;

	v_c = va_arg(args, int);
	if (c == '%')
		ft_putchar_fd('%', 1);
	else if (c == 'c')
		ft_putchar_fd(v_c, 1);
	else
		return (0);
	return (1);
}

size_t	ft_direction_d_i(va_list args)
{
	size_t	len;
	int		num;

	len = 1;
	num = va_arg(args, int);
	ft_putnbr_fd(num, 1);
	while (num >= 10)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

size_t	ft_direction(char c, va_list args)
{
	size_t	byte;

	byte = 0;
	if (c == 'c' || c == '%')
		ft_direction_c_(c, args);
	else if (c == 'd' || c == 'i')
		ft_direction_d_i (args);
	else if (c == 'u')
	{
		byte = sizeof(unsigned int);
		ft_putnbr_unsigned((size_t)va_arg(args, unsigned int));
	}
	else if (c == 's')
		ft_direction_string(args);
	return (byte);
}
