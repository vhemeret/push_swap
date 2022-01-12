/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 00:01:14 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/11 00:01:14 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	_get_median_(Dlist **stack_a)
{
	int		*tab;
	t_list	*tmp_list;
	int		i;
	int		median;

	tab = malloc(sizeof(*tab) * ((*stack_a)->len));
	if (!tab)
		return (0);
	tmp_list = (*stack_a)->begin;
	i = 0;
	while (tmp_list->next != NULL)
	{
		tab[i] = tmp_list->content;
		tmp_list = tmp_list->next;
		i++;
	}
	tab[i] = tmp_list->content;
	median = _sorting_tab_(tab, (*stack_a)->len);
	i = -1;
	__free_basic_int__(&tab);
	return (median);
}

int	_sorting_tab_(int *tab, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < len)
	{
		j = i;
		while (++j < len)
		{
			if (tab[j] < tab[i])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
		}
	}
	return (tab[len / 2]);
}

void	_push_until_bigest_(Dlist **stack_a, Dlist **stack_b, int med, int big)
{
	int	size;
	(void)big;

	size = (*stack_a)->len;
	while ((*stack_a)->len > (size / 2) + 1)
	{
		if ((*stack_a)->begin->content >= med)
			_move_rotate_x_(stack_a, 1);
		else
			_move_push_x_(stack_a, stack_b, 2);
	}
	while ((*stack_a)->len > 1)
	{
		if ((*stack_a)->begin->content == big)
			_move_rotate_x_(stack_a, 1);
		else
			_move_push_x_(stack_a, stack_b, 2);
	}
}

void	_sort_big_(Dlist **stack_a, Dlist **stack_b)
{
	int		bigest;
	int		median;
	int		lenb;
	t_list	*tmp_list;

	bigest = _bigest_(stack_a);
	median = _get_median_(stack_a);
	_push_until_bigest_(stack_a, stack_b, median, bigest);
	_get_info_(stack_a, stack_b);
	lenb = (*stack_b)->len;
	while (lenb != 0)
	{
		_get_info_(stack_a, stack_b);
		_moving_(stack_a, stack_b);
		lenb--;
	}
	_is_faster_to_top_big_(stack_a);
	tmp_list = (*stack_a)->begin;
	while ((*stack_a)->begin->content != _smallest_(stack_a))
	{
		if (tmp_list->rotation == 1)
			_move_rotate_x_(stack_a, 1);
		else
			_move_reverse_rotate_x_(stack_a, 1);
	}
}
