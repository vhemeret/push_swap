/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 23:02:05 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/04 01:02:24 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdio.h>
# include "libft/libft.h"

int			__create_list__(int nb_elem, char **elem, t_list **stack_a);
int			_manage_arg_error_(int ac, char **av);
int			_manage_error_(int ac, char **av, t_list **stack_a);
void		_move_swap_x_(t_list *stack_x, int x);
void		_move_push_x_(t_list **stack_to_move, t_list **stack_x, int x);
void		_move_rotate_x_(t_list **stack_x, int x);
void		_move_reverse_rotate_x_(t_list **stack_x, int x);
t_list		*_lstdelast_(t_list *stack_x);
void		_freedel_(t_list *to_free);
void		ft_putstr(char *str);
int			_check_arg_(int ac, char **av);
int			_check_double_(t_list *stack_a);
int			_check_tab_(int *tab, int len);
int			_check_list_ranked_(t_list	*stack_a);
int			_check_content_(t_list	*stack);
int			_freerror_(t_list *to_free);
int			_check_value_atoi_(long nb);

// SORT SHORT

int			_pos_compar_three_(t_list *stack_a);
void		_sort_three_(t_list	**stack_a);
void		_sort_five_(t_list	**stack_a, t_list **stack_b);

#endif
