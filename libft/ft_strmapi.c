/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 19:04:35 by vahemere          #+#    #+#             */
/*   Updated: 2021/11/13 19:27:06 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dst;
	unsigned int	i;

	if (!s)
		return (NULL);
	dst = ft_strdup(s);
	if (!dst)
		return (NULL);
	i = -1;
	while (dst[++i])
		dst[i] = (f)(i, dst[i]);
	return (dst);
}
