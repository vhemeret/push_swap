/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 16:52:56 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/03 22:11:37 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	_pos_compar_three_(t_list *stack_a)
{
	t_list	*tmp;

	tmp = stack_a;
	if (tmp->content > tmp->next->content
		&& tmp->next->content < tmp->next->next->content
		&& tmp->next->next->content > tmp->content)
		return (1);
	else if (tmp->content > tmp->next->content
		&& tmp->next->content > tmp->next->next->content
		&& tmp->next->next->content < tmp->content)
		return (2);
	else if (tmp->content > tmp->next->content
		&& tmp->next->content < tmp->next->next->content
		&& tmp->next->next->content < tmp->content)
		return (3);
	else if (tmp->content < tmp->next->content
		&& tmp->next->content > tmp->next->next->content
		&& tmp->next->next->content > tmp->content)
		return (4);
	else if (tmp->content < tmp->next->content
		&& tmp->next->content > tmp->next->next->content
		&& tmp->next->next->content < tmp->content)
		return (5);
	return (0);
}

void	_sort_three_(t_list	**stack_a)
{
	int	index;

	index = _pos_compar_three_(*stack_a);
	if (index == 1)
		_move_swap_x_(*stack_a, 1);
	else if (index == 2)
	{
		_move_swap_x_(*stack_a, 1);
		_move_reverse_rotate_x_(stack_a, 1);
	}
	else if (index == 3)
		_move_rotate_x_(stack_a, 1);
	else if (index == 4)
	{
		_move_swap_x_(*stack_a, 1);
		_move_rotate_x_(stack_a, 1);
	}
	else if (index == 5)
		_move_reverse_rotate_x_(stack_a, 1);
}

void	_sort_five_(t_list	**stack_a, t_list **stack_b)
{
	t_list	*tmp_list;

	_move_push_x_(stack_a, stack_b, 2);
	_move_push_x_(stack_a, stack_b, 2);
	_sort_three_(stack_a);
	_move_push_x_(stack_b, stack_a, 1);
	tmp_list = *stack_a;
	_move_push_x_(stack_b, stack_a, 1);
}
