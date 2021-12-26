/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 21:41:15 by vahemere          #+#    #+#             */
/*   Updated: 2021/12/26 14:27:03 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	__print_list__(t_list *stack_a, t_list *stack_b, int elem)
{
	int i;

	if (!stack_a)
		return ;
	i = 0;
	while (++i < elem)
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

int main(int ac, char **av)
{
	t_list	*stack_a = NULL;
	t_list	*stack_b = NULL;
	if (ac <= 1)
		return (0);
	if (!_check_arg_(ac, av))
	{
		ft_putstr("Error\n");
		return (0);
	}
	//if (ac == 2)
	//	_check_arg_av1_(av[1]);
	stack_a = __create_list__(ac, av);
	if (!_check_double_(stack_a))
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (!_check_list_ranked_(stack_a))
		return (0);
	printf("\n***INIT***\n\n");
	__print_list__(stack_a, stack_b, ac);
	printf("\n***SWAP A(SA)***\n\n");
	_move_swap_x_(stack_a);
	__print_list__(stack_a, stack_b, ac);
	printf("\n***MOVE B(PB)***\n\n");
	_move_push_x_(&stack_a, &stack_b);
	__print_list__(stack_a, stack_b, ac);
	printf("\n***MOVE B(PB)(1)***\n\n");
	_move_push_x_(&stack_a, &stack_b);
	__print_list__(stack_a, stack_b, ac);
	printf("\n***SWAP S(SS)***\n\n");
	_move_swap_x_(stack_a);
	_move_swap_x_(stack_b);
	__print_list__(stack_a, stack_b, ac);
	printf("\n***MOVE A***\n\n");
	_move_push_x_(&stack_b, &stack_a);
	__print_list__(stack_a, stack_b, ac);
	printf("\n***MOVE A(1)***\n\n");
	_move_push_x_(&stack_b, &stack_a);
	__print_list__(stack_a, stack_b, ac);
	printf("\n***MOVE ROTATE A(RA)***\n\n");
	_move_rotate_x_(&stack_a);
	__print_list__(stack_a, stack_b, ac);
	printf("\n***MOVE REVERSE ROTATE A(RRA)***\n\n");
	_move_reverse_rotate_x_(&stack_a);
	__print_list__(stack_a, stack_b, ac);
	return (0);
}
