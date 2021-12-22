/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 23:02:05 by vahemere          #+#    #+#             */
/*   Updated: 2021/12/22 14:47:38 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdio.h>
# include "libft/libft.h"

t_list		*_move_swap_x_(t_list *stack_x);
t_list		*_move_push_x_(t_list **stack_to_move, t_list **stack_x);
t_list		*_move_push_a_(t_list **stack_b, t_list *stack_a);
//t_list	_move_rotate_(t_list a, t_list b);
//t_list	_move_reverse_rotate(t_list a, t_list b);

#endif
