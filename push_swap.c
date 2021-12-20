/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 21:41:15 by vahemere          #+#    #+#             */
/*   Updated: 2021/12/20 16:48:13 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

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

t_list	*__create_list__(int nb_elem, char **elem)
{
	t_list *stack_a;
	t_list *tmp;
	int i;
	int nb;

	stack_a = malloc(sizeof(t_list) * (nb_elem - 1));
	if (!stack_a)
		return (NULL);
	nb = ft_atoi(elem[1]);
	stack_a = ft_lstnew(&nb);
	i = 1;
	while (++i < nb_elem)
	{
		nb = ft_atoi(elem[i]);
		tmp = ft_lstnew(&nb);
		ft_lstadd_back(&stack_a, tmp);
	}
	return (stack_a);
}

void	__print_list__(t_list *stack_a, t_list *stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	while ((stack_a && stack_a->content) || (stack_b && stack_b->content))
	{
		if (stack_a && stack_a->content)
		{
			printf("|%i|", stack_a->content);
			stack_a = stack_a->next;
		}
		else
			printf("| |");
		if (stack_b && stack_b->content)
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

int main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	if (ac <= 1 || !_check_arg_(ac, av))
		return (0);
	stack_a = __create_list__(ac, av);
	stack_b = malloc(sizeof(t_list) * (ac - 1));
	if (!stack_b)
		return (0);
	__print_list__(stack_a, stack_b);
	printf("\n***SWAP A***\n\n");
	_move_swap_a_(stack_a);
	__print_list__(stack_a, stack_b);
	printf("\n***MOVE B***\n\n");
	_move_push_b_(&stack_a, &stack_b);
	__print_list__(stack_a, stack_b);
	return (0);
}
