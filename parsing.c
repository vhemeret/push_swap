/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 00:25:12 by vahemere          #+#    #+#             */
/*   Updated: 2021/12/24 01:21:31 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	_check_arg_(int ac, char **av)
{
	int i;
	int j;

	i = 0;
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
	}
	return (1);
}

int	_check_list_ranked_(t_list	*stack_a)
{
	t_list	*tmp_list;
	int		tmp;
	if (!stack_a)
		return (0);
	tmp_list = stack_a;
	while (tmp_list->next != NULL
		&& (tmp_list->content < tmp_list->next->content))
	{
		tmp = tmp_list->content;
		tmp_list = tmp_list->next;
	}
	if (tmp < tmp_list->content && tmp_list->next == NULL)
	{
		_freedel_(tmp_list);
		return (0);
	}
	_freedel_(tmp_list);
	return (1);
}