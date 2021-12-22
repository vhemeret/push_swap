/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 23:17:45 by vahemere          #+#    #+#             */
/*   Updated: 2021/12/21 19:01:16 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

t_list	*_move_swap_x_(t_list *stack_x)
{
	int	tmp;

	tmp = stack_x->content;
	stack_x->content = stack_x->next->content;
	stack_x->next->content = tmp;
	return (stack_x);
}

t_list  *_move_push_x_(t_list **stack_to_move, t_list *stack_x)
{
	int	tmp;

	if (!stack_to_move)
		return (NULL);
	else if (*stack_to_move && stack_x)
	{
		tmp = (*stack_to_move)->content;
		stack_x->content = tmp;
		*stack_to_move = (*stack_to_move)->next;
		
	}
	return (stack_x);
}

t_list  *_move_push_a_(t_list **stack_b, t_list *stack_a)
{
	int	tmp;

	if (!stack_b)
		return (NULL);
	else if (*stack_b && stack_a)
	{
		tmp = (*stack_b)->content;
		stack_a->content = tmp;
		printf("|%i|\n", stack_a->content);
		if (!(*stack_b)->next)
			*stack_b = NULL;
		else
			*stack_b = (*stack_b)->next;
		printf("|%i|\n", (*stack_b)->content);
	}
	return (stack_a);
}