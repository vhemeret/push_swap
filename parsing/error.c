/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 22:14:22 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/10 22:14:39 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	_manage_arg_error_(int ac, char **av)
{
	char	**tab;

	if (ac <= 1
		|| (ac == 2 && (!av[1] || av[1][0] == '\0' || av[1][1] == '\0')))
		return (0);
	if (ac == 2)
	{
		tab = ft_split(av[1], ' ');
		if (!_check_arg_(nb_words(av[1], ' '), tab))
		{
			ft_putstr("Error\n");
			tab = __free_basic_char__(tab, nb_words(av[1], ' '));
			return (0);
		}
		tab = __free_basic_char__(tab, nb_words(av[1], ' '));
	}
	else
	{
		if (!_check_arg_(ac, av))
		{
			ft_putstr("Error\n");
			return (0);
		}
	}
	return (1);
}

int	_manage_error_(Dlist **stack_a)
{
	if ((*stack_a)->len == 1)
	{
		_freedel_(stack_a, 0);
		return (0);
	}
	if (!_check_double_(stack_a))
		return (0);
	if (!_check_list_ranked_(stack_a))
		return (0);
	return (1);
}
