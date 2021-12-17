/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 23:02:05 by vahemere          #+#    #+#             */
/*   Updated: 2021/12/17 17:35:02 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

typedef struct s_list
{
	int	*content;
	struct s_list *next;
}				t_list;

t_list	_move_swap_a_(t_list *stack_a);
t_list	_move_swap_b_(t_list *stack_b);
t_list	_move_push_a_(t_list *stack_a, t_list *stack_b);
t_list	_move_rotate_(t_list a, t_list b);
t_list	_move_reverse_rotate(t_list a, t_list b);

#endif
