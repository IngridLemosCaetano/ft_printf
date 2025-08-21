/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilemos-c <ilemos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:46:12 by ilemos-c          #+#    #+#             */
/*   Updated: 2025/08/21 19:24:15 by ilemos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		num_bytes;

	va_start(args, format);
	i = 0;
	num_bytes = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			num_bytes += ft_direction(format[i + 1], args);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			num_bytes++;
		}
		i++;
	}
	va_end(args);
	return (num_bytes);
}

size_t	ft_nbrlen_unsigned(unsigned int n)
{
	int	i;

	i = 1;
	while (n / 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	ft_putnbr_unsigned(unsigned int n)
{
	if (n >= 10)
	{
		ft_putnbr_unsigned(n / 10);
		ft_putnbr_unsigned(n % 10);
	}
	else
		ft_putchar_fd((n + '0'), 1);
}

// int	main(void)
// {
// 	ft_printf("Char: %c Porcentagem: %%\n", 'a', '%');
// 	ft_printf("Porcentagem: %%\n");
// 	ft_printf("Char: %c\n", 'A');
// 	ft_printf("String: %s\n", "Olá");
// 	ft_printf("Ponteiro: %p\n", (void *)0x1234);
// 	ft_printf("Decimal: %d \n", -100);
// 	ft_printf("Decimal: %i\n", -100);
// 	ft_printf("Unsigned: %u\n", 42);
// 	ft_printf("Hex: %x\n", 255);
// 	ft_printf("HEX: %X\n", 255);
// 	ft_printf("Porcentagem: %%\n");
// 	ft_printf("Null: %s\n", NULL);
// 	return (0);
// }
