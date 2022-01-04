/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 23:17:45 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/03 21:52:09 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	_move_swap_x_(t_list *stack_x, int x)
{
	int	tmp;

	if (!stack_x || !stack_x->next)
		return ;
	tmp = stack_x->content;
	stack_x->content = stack_x->next->content;
	stack_x->next->content = tmp;
	if (x == 1)
		ft_putstr("sa\n");
	else if (x == 2)
		ft_putstr("sb\n");
	else if (x == 3)
		ft_putstr("ss\n");
}

void	_move_push_x_(t_list **stack_to_move, t_list **stack_x, int x)
{
	t_list	*tmp;

	if (!*stack_to_move)
		return ;
	else
	{
		tmp = ft_lstnew(&(*stack_to_move)->content);
		ft_lstadd_front(stack_x, tmp);
		*stack_to_move = (*stack_to_move)->next;
	}
	if (x == 1)
		ft_putstr("pa\n");
	else if (x == 2)
		ft_putstr("pb\n");
}

void	_move_rotate_x_(t_list **stack_x, int x)
{
	t_list	*tmp_list;

	if (!*stack_x || !(*stack_x)->next)
		return ;
	tmp_list = *stack_x;
	*stack_x = (*stack_x)->next;
	ft_lstadd_back(stack_x, tmp_list);
	if (x == 1)
		ft_putstr("ra\n");
	else if (x == 2)
		ft_putstr("rb\n");
	else if (x == 3)
		ft_putstr("rr\n");
}

void	_move_reverse_rotate_x_(t_list **stack_x, int x)
{
	t_list	*new;
	t_list	*tmp_list;

	if (!*stack_x || !(*stack_x)->next)
		return ;
	tmp_list = *stack_x;
	while (tmp_list->next != NULL)
		tmp_list = tmp_list->next;
	new = ft_lstnew(&tmp_list->content);
	ft_lstadd_front(stack_x, new);
	*stack_x = _lstdelast_(*stack_x);
	if (x == 1)
		ft_putstr("rra\n");
	else if (x == 2)
		ft_putstr("rrb\n");
	else if (x == 3)
		ft_putstr("rrr\n");
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
