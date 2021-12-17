/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:32:26 by vahemere          #+#    #+#             */
/*   Updated: 2021/11/13 18:59:41 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_size(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i += 1;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*into_tab(char *res, long int i, unsigned int nb, int minus)
{
	res[i - 1] = '\0';
	i -= 1;
	while (--i >= minus)
	{
		res[i] = (nb % 10) + 48;
		nb /= 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char			*res;
	long int		i;
	int				minus;
	unsigned int	nb;

	i = ft_size(n) + 1;
	minus = 0;
	nb = 0;
	res = malloc(sizeof(*res) * (i));
	if (!res)
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		nb = -n;
		minus = 1;
	}
	else
		nb = n;
	res = into_tab(res, i, nb, minus);
	return (res);
}
