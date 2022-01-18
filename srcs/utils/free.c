/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 19:59:49 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/09 19:59:49 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	__free_basic_int__(int **to_free)
{
	free(*to_free);
	*to_free = NULL;
}

char	**__free_basic_char__(char **to_free, int nb_elem)
{
	int	i;

	i = -1;
	if (nb_elem)
	{
		while (++i <= nb_elem)
		{
			free(to_free[i]);
			to_free[i] = NULL;
		}
	}
	free(to_free);
	to_free = NULL;
	return (to_free);
}

int	__free_split_parsing__(char **to_free, int nb_elem)
{
	int	i;

	i = -1;
	if (nb_elem)
	{
		while (++i <= nb_elem)
		{
			free(to_free[i]);
			to_free[i] = NULL;
		}
	}
	free(to_free);
	to_free = NULL;
	return (0);
}
