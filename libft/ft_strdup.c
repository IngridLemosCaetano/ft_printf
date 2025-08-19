/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilemos-c <ilemos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:28:57 by ilemos-c          #+#    #+#             */
/*   Updated: 2025/08/09 11:48:39 by ilemos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		size;
	char	*dest;

	size = ft_strlen(s);
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, s, (size + 1));
	return (dest);
}
/*
int	main(void)
{
	const char *s = "Ingrid";
	char		*dest;
	dest = ft_strdup(s);
	printf("String destino = %s\n", dest);
	free (dest);
	return (0);
}*/
