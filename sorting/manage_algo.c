/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 02:05:53 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/10 02:05:53 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	__manage_algo__(Dlist **stack_a, Dlist **stack_b)
{
	if ((*stack_a)->len == 2)
		_move_swap_x_(stack_a, 1);
	else if ((*stack_a)->len == 3)
		_sort_three_(stack_a);
	else if ((*stack_a)->len <= 10)
		_sort_small_(stack_a, stack_b);
	else
		_sort_big_(stack_a, stack_b);
}
