/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilemos-c <ilemos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:24:39 by ilemos-c          #+#    #+#             */
/*   Updated: 2025/08/09 11:48:46 by ilemos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*new_str;
	int		len_s1;
	int		len_s2;

	i = 0;
	j = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new_str = (char *)malloc(len_s1 + len_s2 + 1);
	if (new_str == NULL)
		return (NULL);
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new_str[i] = s2[j++];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
/*
int	main(void)
{
	char const *s1 = "42 ";
	char const *s2 = "São Paulo";
	char	*new_str;
	new_str = ft_strjoin(s1, s2);
	if ( new_str == NULL)
		printf("Não foi possível concatenar as strings.\n");
	else{
		printf("%s\n", new_str);
		free(new_str);
	}
	return 0;
}*/
