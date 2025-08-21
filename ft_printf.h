/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilemos-c <ilemos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:27:20 by ilemos-c          #+#    #+#             */
/*   Updated: 2025/08/21 19:21:43 by ilemos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *s);

size_t	ft_nbrlen_unsigned(unsigned int n);
void	ft_putnbr_unsigned(unsigned int n);

size_t	ft_direction(char c, va_list args);
size_t	ft_direction_c_(char c, va_list args);
size_t	ft_direction_d_i(va_list args);
size_t	ft_direction_string(va_list args);

#endif
