/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 23:17:45 by vahemere          #+#    #+#             */
/*   Updated: 2021/12/22 14:56:29 by vahemere         ###   ########.fr       */
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

t_list  *_move_push_x_(t_list **stack_to_move, t_list **stack_x)
{
	t_list	*tmp;

	if (!stack_to_move)
		return (NULL);
	else
	{
		tmp = ft_lstnew(&(*stack_to_move)->content);
		ft_lstadd_front(stack_x, tmp);
		*stack_to_move = (*stack_to_move)->next;
		printf("stack_x = %i\n", (*stack_x)->content);
		printf("stack_x = %i\n", (*stack_x)->next->content);
		printf("stack_x = %i\n", (*stack_to_move)->content);
		printf("stack_x = %i\n", (*stack_to_move)->next->content);
	}
	return (*stack_x);
}
/*
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
			(*stack_b)->next = NULL;
		printf("|%i|\n", (*stack_b)->content);
	}
	return (stack_a);
}
*/