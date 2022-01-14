/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 01:41:39 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/08 01:41:39 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	_move_swap_x_(t_Dlist **stack_x, int x)
{
	int	tmp;

	if (!(*stack_x) || !(*stack_x)->begin->next)
		return ;
	tmp = (*stack_x)->begin->content;
	(*stack_x)->begin->content = (*stack_x)->begin->next->content;
	(*stack_x)->begin->next->content = tmp;
	if (x == 1)
		ft_putstr("sa\n");
	else if (x == 2)
		ft_putstr("sb\n");
	else if (x == 3)
		ft_putstr("ss\n");
}

void	_move_push_x_(t_Dlist **stack_to_move, t_Dlist **stack_x, int x)
{
	if (!*stack_to_move)
		return ;
	else
	{
		add_front_lst(stack_x, (*stack_to_move)->begin->content);
		if ((*stack_to_move)->begin->next)
			del_front_list(*stack_to_move);
		else if (!(*stack_to_move)->begin->next)
			_freedel_(stack_to_move, 0);
	}
	if (x == 1)
		ft_putstr("pa\n");
	else if (x == 2)
		ft_putstr("pb\n");
}

void	_move_rotate_x_(t_Dlist **stack_x, int x)
{
	if (!*stack_x || !(*stack_x)->begin->next)
		return ;
	add_back_lst(stack_x, (*stack_x)->begin->content);
	del_front_list(*stack_x);
	if (x == 1)
		ft_putstr("ra\n");
	else if (x == 2)
		ft_putstr("rb\n");
	else if (x == 3)
		ft_putstr("rr\n");
}

void	_move_reverse_rotate_x_(t_Dlist **stack_x, int x)
{
	if (!*stack_x || !(*stack_x)->begin->next)
		return ;
	else
	{
		add_front_lst(stack_x, (*stack_x)->end->content);
		del_back_list(*stack_x);
	}
	if (x == 1)
		ft_putstr("rra\n");
	else if (x == 2)
		ft_putstr("rrb\n");
	else if (x == 3)
		ft_putstr("rrr\n");
}
