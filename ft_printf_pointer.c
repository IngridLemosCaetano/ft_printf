/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 18:05:54 by ingrid            #+#    #+#             */
/*   Updated: 2025/08/22 20:35:41 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_len(void *ptr)
{
	int				len;
	unsigned long	new_ptr;

	len = 2;
	if (!ptr)
		return (3);
	new_ptr = (unsigned long)ptr;
	ft_putptr_hex(ptr);
	while (new_ptr / 16)
	{
		new_ptr /= 16;
		len++;
	}
	return (len);
}

void	ft_puthex_ulong(unsigned long n)
{
	int		rest;
	char	c;

	if (n >= 16)
		ft_puthex_ulong(n / 16);
	rest = n % 16;
	if (rest < 10)
	{
		c = rest + '0';
		write(1, &c, 1);
	}
	else
	{
		c = 'a' + (rest - 10);
		write(1, &c, 1);
	}
}

void	ft_putptr_hex(void *ptr)
{
	unsigned long	n;

	write(1, "0x", 2);
	if (!ptr)
	{
		write(1, "0", 1);
		return ;
	}
	n = (unsigned long)ptr;
	ft_puthex_ulong(n);
}
