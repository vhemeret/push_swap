/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:51:15 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/10 21:51:15 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	_smallest_(t_Dlist **stack_x)
{
	t_list	*tmp_list;
	int		smallest;

	tmp_list = (*stack_x)->begin;
	smallest = tmp_list->content;
	while (tmp_list)
	{
		if (tmp_list->content < smallest)
			smallest = tmp_list->content;
		tmp_list = tmp_list->next;
	}
	return (smallest);
}

int	_pos_smallest_(t_Dlist **stack_x)
{
	t_list	*tmp_list;
	int		min;
	int		index;

	tmp_list = (*stack_x)->begin;
	min = tmp_list->content;
	index = 0;
	while (tmp_list)
	{
		if (tmp_list->content < min)
		{
			min = tmp_list->content;
			index += 1;
		}
		tmp_list = tmp_list->next;
	}
	return (index);
}

int	_bigest_(t_Dlist **stack_x)
{
	t_list	*tmp_list;
	int		bigest;

	tmp_list = (*stack_x)->begin;
	bigest = tmp_list->content;
	while (tmp_list)
	{
		if (tmp_list->content > bigest)
			bigest = tmp_list->content;
		tmp_list = tmp_list->next;
	}
	return (bigest);
}

int	_pos_bigest_(t_Dlist **stack_x)
{
	t_list	*tmp_list;
	int		max;
	int		index;

	tmp_list = (*stack_x)->begin;
	max = tmp_list->content;
	index = 0;
	while (tmp_list)
	{
		if (tmp_list->content > max)
		{
			max = tmp_list->content;
			index += 1;
		}
		tmp_list = tmp_list->next;
	}
	return (index);
}

void	_is_faster_to_top_(t_Dlist **stack_x, int pos_content, int content)
{
	int	size;

	size = (*stack_x)->len;
	while ((*stack_x)->begin->content != content)
	{
		if (pos_content < size / 2)
			_move_rotate_x_(stack_x, 1);
		else
			_move_reverse_rotate_x_(stack_x, 1);
	}
}
