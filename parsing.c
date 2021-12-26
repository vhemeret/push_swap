/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 00:25:12 by vahemere          #+#    #+#             */
/*   Updated: 2021/12/26 14:26:50 by vahemere         ###   ########.fr       */
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

int	_check_double_(t_list *stack_a)
{
	int		*tab;
	t_list	*tmp_list;
	int 	i;
	int		j;
	int		k;

	tab = malloc(sizeof(int) * (ft_lstsize(stack_a)));
	if (!tab)
		return (0);
	tmp_list = stack_a;
	i = 0;
	while (tmp_list->next != NULL)
	{
		tab[i] = tmp_list->content;
		tmp_list = tmp_list->next;
		i++;
	}
	tab[i] = tmp_list->content;
	j = -1;
	while (++j <= i)
	{
		k = j;
		while (++k <= i)
			if (tab[k] == tab[j])
			{
				_freedel_(tmp_list);
				return (0);
			}
	}
	return (1);
}

/*int	_check_arg_av1_(char *av)
{
	int	i;
	int	*tab;

	i = -1;
	(void)av;
	while (av[++i])
	{
		if (ft_isdigit(ft_atoi(av[i])))
			j++;
	}
	return ;
}*/


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
	return (1);
}
