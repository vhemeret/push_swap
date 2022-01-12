/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 00:25:12 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/11 00:41:44 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	_check_arg_(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		while (av[i][j])
		{
			if (av[i][j] >= '0' && av[i][j] <= '9')
			{
				while (av[i][j] >= '0' && av[i][j] <= '9')
					j++;
			}
			else
				return (0);
		}
	}
	return (1);
}

int	_check_value_atoi_(long nb)
{
	if (nb < -2147483648 || nb > 2147483647)
		return (0);
	return (1);
}

int	_check_double_(Dlist **stack_a)
{
	int		*tab;
	t_list	*tmp_list;
	int		i;

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
	if (!_check_tab_(tab, i))
	{
		__free_basic_int__(&tab);
		_freedel_(stack_a, 1);
		return (0);
	}
	else
		__free_basic_int__(&tab);
	return (1);
}

int	_check_tab_(int *tab, int len)
{
	int	k;
	int	j;

	j = -1;
	while (++j <= len)
	{
		k = j;
		while (++k <= len)
		{
			if (tab[k] == tab[j])
				return (0);
		}
	}
	return (1);
}

int	_check_list_ranked_(Dlist **stack_a)
{
	t_list	*tmp_list;
	int		tmp;

	if (!stack_a)
		return (0);
	tmp_list = (*stack_a)->begin;
	while (tmp_list->next != NULL
		&& (tmp_list->content < tmp_list->next->content))
	{
		tmp = tmp_list->content;
		tmp_list = tmp_list->next;
	}
	if (tmp < tmp_list->content && tmp_list->next == NULL)
	{
		_freedel_(stack_a, 0);
		return (0);
	}
	return (1);
}
