/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 23:31:30 by vahemere          #+#    #+#             */
/*   Updated: 2021/10/25 19:16:02 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_src;

	i = -1;
	len_src = ft_strlen(src);
	if (!dst || !src)
		return (0);
	if (dstsize > 0)
	{
		while ((++i < (dstsize - 1)) && src[i])
			dst[i] = src[i];
		dst[i] = '\0';
		while (src[i])
			i++;
	}
	return (len_src);
}
