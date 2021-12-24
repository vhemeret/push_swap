/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 23:02:05 by vahemere          #+#    #+#             */
/*   Updated: 2021/12/24 01:18:11 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdio.h>
# include "libft/libft.h"

t_list		*_move_swap_x_(t_list *stack_x);
t_list		*_move_push_x_(t_list **stack_to_move, t_list **stack_x);
t_list		*_move_rotate_x_(t_list **stack_x);
t_list		*_move_reverse_rotate_x_(t_list **stack_x);
t_list		*_lstdelast_(t_list *stack_x);
void		_freedel_(t_list *stack);
int			_check_arg_(int ac, char **av);
int			_check_list_ranked_(t_list	*stack_a);

#endif
