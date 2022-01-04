/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 22:14:22 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/04 01:01:11 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	_manage_arg_error_(int ac, char **av)
{
	if (ac <= 2)
		return (0);
	if (!_check_arg_(ac, av))
	{
		ft_putstr("Error\n");
		return (0);
	}
	return (1);
}

int	_manage_error_(int ac, char **av, t_list **stack_a)
{
	if (!__create_list__(ac, av, stack_a))
		return (0);
	if (!_check_double_(*stack_a))
		return (0);
	if (!_check_list_ranked_(*stack_a))
		return (0);
	return (1);
}
