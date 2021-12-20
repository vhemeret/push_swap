/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 23:18:29 by vahemere          #+#    #+#             */
/*   Updated: 2021/12/20 16:52:40 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

t_list  *_move_push_a_(t_list *stack_a, t_list *stack_b)
{
	t_list	*new;

	if (!stack_b)
		return (NULL);
	else if (stack_b && stack_a)
	{
		new = stack_b;
		stack_b = stack_b->next;
		new->next = stack_a;
		stack_a = new;
	}
	return (stack_a);
}

t_list  *_move_push_b_(t_list **stack_a, t_list **stack_b)
{
	//t_list	*new;

	if (!stack_a)
		return (NULL);
	else if (stack_a && stack_b)
	{
		//new = *stack_a;
		(*stack_b)->next = *stack_b;
		*stack_b = *stack_a;
		*stack_a = (*stack_a)->next;
	}
	return (*stack_b);
}