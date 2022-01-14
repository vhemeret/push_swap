/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 01:01:09 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/08 01:01:09 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	__create_list__(int nb_elem, char **elem, t_Dlist **stack_a, int x)
{
	int		i;
	long	nb;

	i = 0;
	if (x == 1)
		i = -1;
	while (++i < nb_elem)
	{
		nb = ft_atoi(elem[i]);
		if (!_check_value_atoi_(nb))
		{
			_freedel_(stack_a, 1);
			return (0);
		}
		add_back_lst(stack_a, nb);
	}
	if (x == 1)
		elem = __free_basic_char__(elem, nb_elem);
	return (1);
}

int	main(int ac, char **av)
{
	t_Dlist	*stack_a;
	t_Dlist	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (!_manage_arg_error_(ac, av))
		return (0);
	if (ac == 2)
	{
		if (!__create_list__(nb_words(av[1], ' '),
				ft_split(av[1], ' '), &stack_a, 1))
			return (0);
	}
	else
		if (!__create_list__(ac, av, &stack_a, 0))
			return (0);
	if (!_manage_error_(&stack_a))
		return (0);
	__manage_algo__(&stack_a, &stack_b);
	if (!list_empty(stack_a))
		_freedel_(&stack_a, 0);
	if (!list_empty(stack_b))
		_freedel_(&stack_b, 0);
	return (0);
}
