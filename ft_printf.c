/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:46:12 by ilemos-c          #+#    #+#             */
/*   Updated: 2025/08/24 13:13:26 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			len += ft_direction(format[i + 1], args);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

int	ft_direction(char c, va_list args)
{
	if (c == '%')
		return (ft_putchar('%'));
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_len(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'u')
		return (ft_putnbr_len_unsigned(va_arg(args, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_hex_len(va_arg(args, unsigned int), c));
	if (c == 'p')
		return (ft_putptr_len(va_arg(args, void *)));
	else
		return (0);
}

// int	main(void)
// {
// 	printf(" %p %p ", 0, 0);
// 	ft_printf("Original\n Ponteiro: %p", 0);
// 	return (0);
// }
// int	main(void)
// {
// 	int	x = 10;
// 	int	*ptr = NULL;
// 	int	num;
// 	printf("ponteiro: %p\n", &x);
// 	ft_printf("ponteiro: %p\n", &x);
// 	printf("ponteiro: %p e len: %d\n", &ptr, ft_putptr_len(ptr));
// 	num = ft_printf("ponteiro: %p\n", &ptr);
// 	printf("%d\n", num);
// 	return (0);
// }

// int	main(void)
// {
// 	ft_printf("Char: %c Porcentagem: %%\n", 'a', '%');
// 	ft_printf("Porcentagem: %%\n");
// 	ft_printf("Char: %c\n", 'A');
// 	ft_printf("String: %s\n", "Olá");
// 	ft_printf("Ponteiro: %p\n", (void *)0x1234);
// 	ft_printf("Ponteiro: %p\n", -1);
// 	ft_printf("Decimal: %d \n", -100);
// 	ft_printf("Decimal: %i\n", -100);
// 	ft_printf("Unsigned: %u\n", 42);
// 	ft_printf("Hex: %x\n", 255);
// 	ft_printf("HEX: %X\n", 255);
// 	ft_printf("Porcentagem: %%\n");
// 	ft_printf("Null: %s\n", NULL);
// 	return (0);
// }
