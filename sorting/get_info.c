/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 23:52:23 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/11 23:52:23 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	_attribute_index_(t_Dlist **stack_x)
{
	t_list	*tmp_list;
	int		i;

	if (!(*stack_x))
		return ;
	i = 0;
	tmp_list = (*stack_x)->begin;
	while (tmp_list)
	{
		tmp_list->index = (*stack_x)->len - i;
		tmp_list = tmp_list->next;
		i++;
	}
}

void	_find_associate_(t_Dlist **stack_a, t_Dlist **stack_b)
{
	t_list	*tmp_listb;
	t_list	*tmp_lista;
	int		bigest;

	if (!(*stack_b) || !(*stack_a))
		return ;
	tmp_listb = (*stack_b)->begin;
	while (tmp_listb)
	{
		bigest = _bigest_(stack_a);
		tmp_lista = (*stack_a)->begin;
		while (tmp_lista)
		{
			if (tmp_lista->content > tmp_listb->content)
				if (tmp_lista->content < bigest)
					bigest = tmp_lista->content;
			tmp_lista = tmp_lista->next;
		}
		tmp_listb->associate = bigest;
		tmp_listb = tmp_listb->next;
	}
}

void	_is_faster_to_top_big_(t_Dlist **stack_x)
{
	t_list	*tmp_list;
	int		size;

	if (!(*stack_x))
		return ;
	tmp_list = (*stack_x)->begin;
	size = (*stack_x)->len;
	while (tmp_list)
	{
		if (tmp_list->index >= (size / 2) + 1)
		{
			tmp_list->to_top = size - tmp_list->index - 1;
			tmp_list->rotation = 1;
		}
		else
		{
			tmp_list->to_top = tmp_list->index + 1;
			tmp_list->rotation = 2;
		}
		tmp_list = tmp_list->next;
	}
}

void	_calculate_of_top_t_(t_Dlist **stack_a, t_Dlist **stack_b)
{
	t_list	*tmp_lista;
	t_list	*tmp_listb;

	if (!(*stack_b) || !(*stack_a))
		return ;
	tmp_listb = (*stack_b)->begin;
	while (tmp_listb)
	{
		tmp_lista = (*stack_a)->begin;
		while (tmp_listb->associate != tmp_lista->content)
			tmp_lista = tmp_lista->next;
		tmp_listb->to_top_t = tmp_listb->to_top + tmp_lista->to_top;
		tmp_listb = tmp_listb->next;
	}
}

void	_get_info_(t_Dlist **stack_a, t_Dlist **stack_b)
{
	_attribute_index_(stack_a);
	_attribute_index_(stack_b);
	_find_associate_(stack_a, stack_b);
	_is_faster_to_top_big_(stack_a);
	_is_faster_to_top_big_(stack_b);
	_calculate_of_top_t_(stack_a, stack_b);
}
