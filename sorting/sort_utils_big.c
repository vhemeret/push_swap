/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_big.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 20:00:19 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/11 20:00:19 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*_find_better_top_t_(t_Dlist **stack_b)
{
	t_list	*tmp_list;
	t_list	*better;

	tmp_list = (*stack_b)->begin;
	better = tmp_list;
	while (tmp_list)
	{
		if (tmp_list->to_top_t < better->to_top_t)
			better = tmp_list;
		tmp_list = tmp_list->next;
	}
	return (better);
}

int	_moving_better_top_b_(t_Dlist **stack_b)
{
	t_list	*better;
	int		better_rotation;
	int		better_content;
	int		better_associate;

	better = _find_better_top_t_(stack_b);
	better_content = better->content;
	better_rotation = better->rotation;
	better_associate = better->associate;
	while ((*stack_b)->begin->content != better_content)
	{
		if (better_rotation == 1)
			_move_rotate_x_(stack_b, 2);
		else
			_move_reverse_rotate_x_(stack_b, 2);
	}
	return (better_associate);
}

void	_moving_better_top_a_(t_Dlist **stack_a, int associate)
{
	t_list	*tmp_list;
	int		rotation;
	int		content;

	tmp_list = (*stack_a)->begin;
	while (tmp_list->content != associate)
		tmp_list = tmp_list->next;
	rotation = tmp_list->rotation;
	content = tmp_list->content;
	while ((*stack_a)->begin->content != content)
	{
		if (rotation == 1)
			_move_rotate_x_(stack_a, 1);
		else
			_move_reverse_rotate_x_(stack_a, 1);
	}
}

void	_moving_(t_Dlist **stack_a, t_Dlist **stack_b)
{
	int	associate_to_b;

	associate_to_b = _moving_better_top_b_(stack_b);
	_moving_better_top_a_(stack_a, associate_to_b);
	_move_push_x_(stack_b, stack_a, 1);
}
