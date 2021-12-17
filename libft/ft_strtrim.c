/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:30:17 by vahemere          #+#    #+#             */
/*   Updated: 2021/11/28 01:19:57 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	is_set(char c, const char *set)
{
	size_t	i;

	i = -1;
	while (set[++i])
		if (c == set[i])
			return (0);
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	head;
	size_t	foot;

	head = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	while (s1[head] && !is_set(s1[head], set))
		head++;
	if (s1[head] == '\0')
		return (ft_strdup("\0"));
	foot = ft_strlen(s1) - 1;
	while (foot && !is_set(s1[foot], set))
		foot--;
	return (ft_substr(s1, head, (foot - head) + 1));
}
