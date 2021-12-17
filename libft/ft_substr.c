/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 09:38:08 by vahemere          #+#    #+#             */
/*   Updated: 2021/11/28 00:57:07 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = malloc(sizeof(char) * len + 1);
	if (dest == NULL)
		return (NULL);
	else if (!s)
		return (NULL);
	if (ft_strlen(s) > start)
	{
		while (i < len && s[start])
		{
			dest[i] = s[start];
			start++;
			i++;
		}
	}
	dest[i] = '\0';
	return (dest);
}
