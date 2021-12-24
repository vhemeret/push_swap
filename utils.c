/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:52:38 by vahemere          #+#    #+#             */
/*   Updated: 2021/12/24 00:16:05 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	_freedel_(t_list *to_free)
{
	while (to_free->next != NULL)
	{
		free(to_free);
		to_free = to_free->next;
	}
}

t_list	*_lstdelast_(t_list *stack_x)
{
	t_list	*tmp_list;

	tmp_list = stack_x;
	while (stack_x->next != NULL)
		stack_x = stack_x->next;
	stack_x->content = 0;
	free(stack_x);
	return (tmp_list);
}