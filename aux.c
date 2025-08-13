/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilemos-c <ilemos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:57:32 by ilemos-c          #+#    #+#             */
/*   Updated: 2025/08/13 16:29:15 by ilemos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*new_s1;
	unsigned char	*new_s2;

	i = 0;
	new_s1 = (unsigned char *)s1;
	new_s2 = (unsigned char *)s2;
	while ((new_s1[i] != '\0' || new_s2[i] != '\0') && i < n)
	{
		if (new_s1[i] != new_s2[i])
			return (new_s1[i] - new_s2[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_length;
	size_t	src_length;

	i = 0;
	dst_length = 0;
	src_length = 0;
	while (dst[dst_length] && dst_length < size)
		dst_length++;
	while (src[src_length])
		src_length++;
	if (dst_length == size)
		return (size + src_length);
	while (src[i] && (dst_length + i + 1 < size))
	{
		dst[dst_length + i] = src[i];
		i++;
	}
	dst[dst_length + i] = '\0';
	return (dst_length + src_length);
}

int	ft_type_converter(char *c)
{
	if (ft_strncmp(c, "%c", 2) == 0)
		return (1);
	else if (ft_strncmp(c, "%s", 2) == 0)
		return (2);
	else if (ft_strncmp(c, "%p", 2) == 0)
		return (3);
	else if (ft_strncmp(c, "%d", 2) == 0)
		return (4);
	else if (ft_strncmp(c, "%i", 2) == 0)
		return (5);
	else if (ft_strncmp(c, "%u", 2) == 0)
		return (6);
	else if (ft_strncmp(c, "%x", 2) == 0)
		return (7);
	else if (ft_strncmp(c, "%X", 2) == 0)
		return (8);
	else if (ft_strncmp(c, "%%", 2) == 0)
		return (9);
	else
		return (0);
}

/*
int	main(void)
{
	char *converter_1 = "%c";
	printf("%s -> %d\n",converter_1, ft_type_converter(converter_1));
	char *converter_2 = "%s";
	printf("%s -> %d\n",converter_2, ft_type_converter(converter_2));
	char *converter_3 = "%p";
	printf("%s -> %d\n",converter_3, ft_type_converter(converter_3));
	char *converter_4 = "%d";
	printf("%s -> %d\n", converter_4, ft_type_converter(converter_4));
	char *converter_5 = "%i";
	printf("%s -> %d\n", converter_5, ft_type_converter(converter_5));
	char *converter_6 = "%u";
	printf("%s -> %d\n", converter_6, ft_type_converter(converter_6));
	char *converter_7 = "%x";
	printf("%s -> %d\n", converter_7, ft_type_converter(converter_7));
	char *converter_8 = "%X";
	printf("%s -> %d\n", converter_8, ft_type_converter(converter_8));
	char *converter_9 = "%%";
	printf("%s -> %d\n", converter_9,  ft_type_converter(converter_9));
	char *converter_10 = "mm";
	printf("%s -> %d\n", converter_10, ft_type_converter(converter_10));
	return (0);
}*/

int	ft_count_converter(char *str)
{
	int		count;
	int		i;
	char	substr[3];

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			substr[0] = str[i];
			substr[1] = str[i + 1];
			substr[2] = '\0';
			if (ft_strncmp(substr, "%c", 3) == 0 || ft_strncmp(substr, "%s", 3) == 0
			|| ft_strncmp(substr, "%p", 3) == 0 || ft_strncmp(substr, "%d", 3) == 0
			|| ft_strncmp(substr, "%i", 3) == 0 || ft_strncmp(substr, "%u", 3) == 0
			|| ft_strncmp(substr, "%x", 3) == 0 || ft_strncmp(substr, "%X", 3) == 0
			|| ft_strncmp(substr, "%%", 3) == 0)
			{
				count++;
				i++;
			}
		}
		i++;
	}
	return (count);
}

int	main(void)
{
	char	*str = "Ingrid %p Bom %p Dia %f %p";
	int		count = ft_count_converter(str);
	printf("Quantidade de placeholder: %d\n", count);
	return (0);
}
