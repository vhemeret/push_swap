/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 23:17:45 by vahemere          #+#    #+#             */
/*   Updated: 2021/12/24 00:16:07 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

t_list	*_move_swap_x_(t_list *stack_x)
{
	int	tmp;

	if (!stack_x || !stack_x->next)
		return (NULL);
	tmp = stack_x->content;
	stack_x->content = stack_x->next->content;
	stack_x->next->content = tmp;
	return (stack_x);
}

t_list  *_move_push_x_(t_list **stack_to_move, t_list **stack_x)
{
	t_list	*tmp;

	if (!*stack_to_move || !(*stack_to_move)->next)
		return (NULL);
	else
	{
		tmp = ft_lstnew(&(*stack_to_move)->content);
		ft_lstadd_front(stack_x, tmp);
		*stack_to_move = (*stack_to_move)->next;
	}
	return (*stack_x);
}

t_list	*_move_rotate_x_(t_list **stack_x)
{
	t_list	*tmp_list;

	if (!*stack_x || !(*stack_x)->next)
		return (NULL);
	tmp_list = *stack_x;
	*stack_x = (*stack_x)->next;
	ft_lstadd_back(stack_x, tmp_list);
	return (*stack_x);
}

t_list	*_move_reverse_rotate_x_(t_list **stack_x)
{
	t_list	*new;
	t_list	*tmp_list;

	if (!*stack_x || !(*stack_x)->next)
		return (NULL);
	tmp_list = *stack_x;
	while (tmp_list->next != NULL)
		tmp_list = tmp_list->next;
	new = ft_lstnew(&tmp_list->content);
	ft_lstadd_front(stack_x, new);
	*stack_x = _lstdelast_(*stack_x);
	_freedel_(tmp_list);
	return (*stack_x);
}
