/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 18:05:54 by ingrid            #+#    #+#             */
/*   Updated: 2025/08/22 20:00:37 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_len(void *ptr)
{
	int				len;
	unsigned long	new_ptr;

	len = 2;
	new_ptr = (unsigned long)ptr;
	if (!ptr)
		return (len++);
	ft_putptr_hex(ptr);
	while (new_ptr / 16)
	{
		new_ptr /= 16;
		len++;
	}
	return (len++);
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
	char			c;

	n = (unsigned long)ptr;
	write(1, "0x", 2);
	if (!ptr)
	{
		c = '0';
		write(1, &c, 1);
		return ;
	}
	ft_puthex_ulong(n);
}

// int	main(void)
// {
// 	int	x = 10;
// 	int	*ptr = NULL;
// 	printf("ponteiro: %p e len: %d\n", &x, ft_putptr_len(&x));
// 	printf("ponteiro: %p e len: %d\n", &ptr, ft_putptr_len(ptr));
// 	return (0);
// }
