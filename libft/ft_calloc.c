/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:29:49 by vahemere          #+#    #+#             */
/*   Updated: 2021/11/09 15:24:39 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nbem, size_t size)
{
	void	*arr;

	arr = malloc(nbem * size);
	if (arr == NULL)
		return (NULL);
	arr = ft_memset(arr, 0, (nbem * size));
	return (arr);
}
