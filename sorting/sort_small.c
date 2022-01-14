/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:15:01 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/10 16:15:01 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	_sort_small_(t_Dlist **stack_a, t_Dlist **stack_b)
{
	int	pos_smallest;
	int	smallest;
	int	cut;
	int	b_len;

	if ((*stack_a)->len >= 3)
		cut = 3;
	else
		cut = 0;
	while ((*stack_a)->len > cut)
	{
		pos_smallest = _pos_smallest_(stack_a);
		smallest = _smallest_(stack_a);
		_is_faster_to_top_(stack_a, pos_smallest, smallest);
		_move_push_x_(stack_a, stack_b, 2);
	}
	if ((*stack_a)->len == 3)
		_sort_three_(stack_a);
	b_len = (*stack_b)->len;
	while (b_len)
	{
		_move_push_x_(stack_b, stack_a, 1);
		b_len--;
	}
}
