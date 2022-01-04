/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 21:41:15 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/04 01:04:00 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	__print_list__(t_list *stack_a, t_list *stack_b, int elem)
{
	int	i;

	if (!stack_a)
		return ;
	i = 0;
	while (++i < elem)
	{
		if (stack_a)
		{
			printf("|%i|", stack_a->content);
			stack_a = stack_a->next;
		}
		else
			printf("| |");
		if (stack_b)
		{
			printf(" |%i|\n", stack_b->content);
			stack_b = stack_b->next;
		}
		else
			printf(" | |\n");
	}
	printf(" -   - \n");
	printf(" A   B \n");
}

int	__create_list__(int nb_elem, char **elem, t_list **stack_a)
{
	t_list	*tmp;
	int		i;
	long	nb;

	nb = ft_atoi(elem[1]);
	*stack_a = ft_lstnew((int *)&nb);
	if (!_check_value_atoi_(nb))
		return (_freerror_(*stack_a));
	i = 1;
	while (++i < nb_elem)
	{
		nb = ft_atoi(elem[i]);
		if (!_check_value_atoi_(nb))
			return (_freerror_(*stack_a));
		tmp = ft_lstnew((int *)&nb);
		ft_lstadd_back(stack_a, tmp);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	if (!_manage_arg_error_(ac, av))
		return (0);
	stack_a = malloc(sizeof(t_list) * (ac - 1));
	if (!stack_a)
		return (0);
	if (!_manage_error_(ac, av, &stack_a))
		return (0);
	__create_list__(ac, av, &stack_a);
	printf("\n***INIT***\n\n");
	__print_list__(stack_a, stack_b, ac);
	printf("\n");
	if (ft_lstsize(stack_a) == 3)
		_sort_three_(&stack_a);
	else if (ft_lstsize(stack_a) == 5)
		_sort_five_(&stack_a, &stack_b);
	printf("\n***SORTED***\n\n");
	__print_list__(stack_a, stack_b, ac);
	return (0);
}
