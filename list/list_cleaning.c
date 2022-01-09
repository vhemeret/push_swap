/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_cleaning.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 01:40:07 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/08 01:40:07 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	*_freedel_(Dlist **to_free, int print_error)
{
	t_list	*tmp_list;

	if (print_error == 1)
		ft_putstr("Error\n");
	while (!list_empty(*to_free))
	{
		if ((*to_free)->begin == (*to_free)->end)
		{
			free((*to_free)->begin);
			(*to_free)->begin = NULL;
			free(*to_free);
			*to_free = NULL;
			return (NULL);
		}
		tmp_list = (*to_free)->begin;
		(*to_free)->begin = (*to_free)->begin->next;
		(*to_free)->begin->back = NULL;
		tmp_list->next = NULL;
		tmp_list->back = NULL;
		free(tmp_list);
		tmp_list = NULL;
		(*to_free)->len -= 1;
	}
	return (NULL);
}
