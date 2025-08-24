/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 18:05:54 by ingrid            #+#    #+#             */
/*   Updated: 2025/08/24 12:49:27 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_len(void *ptr)
{
	int				len;
	unsigned long	ptr_long;

	len = 2;
	ptr_long = (unsigned long)ptr;
	if (!ptr)
	{
		write(1, "0x0", 3);
		return (3);
	}
	write(1, "0x", 2);
	ft_puthex_ulong(ptr_long);
	while (ptr_long)
	{
		ptr_long /= 16;
		len++;
	}
	return (len);
}

void	ft_puthex_ulong(unsigned long n)
{
	char	c;
	int		rest;

	if (n >= 16)
		ft_puthex_ulong(n / 16);
	rest = n % 16;
	if (rest < 10)
		c = rest + '0';
	else
		c = 'a' + (rest - 10);
	write(1, &c, 1);
}

// void	ft_putptr_hex(void *ptr)
// {
// 	unsigned long	n;

// 	n = (unsigned long)ptr;
// 	write(1, "0x", 2);
// 	if (!ptr)
// 	{
// 		write(1, "0", 1);
// 		return ;
// 	}
// 	ft_puthex_ulong(n);
// }
