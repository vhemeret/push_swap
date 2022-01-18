/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 01:01:55 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/18 16:37:17 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	int				index;
	int				associate;
	int				to_top;
	int				to_top_t;
	int				rotation;
	struct s_list	*next;
	struct s_list	*back;
}				t_list;

typedef struct Dlist
{
	int				len;
	struct s_list	*begin;
	struct s_list	*end;
}				t_Dlist;

/*
**	MANAGE AND DATA LIST
*/
int		__create_list__(int nb_elem, char **elem, t_Dlist **stack_a, int x);
int		list_empty(t_Dlist *li);
int		list_len(t_Dlist *li);
int		list_begin(t_Dlist *li);
int		list_end(t_Dlist *li);
t_Dlist	*add_back_lst(t_Dlist **li, int content);
t_Dlist	*add_front_lst(t_Dlist **li, int content);
void	__malloc_t_dlist__(t_Dlist **li, t_list *new_element);
t_Dlist	*del_back_list(t_Dlist *li);
t_Dlist	*del_front_list(t_Dlist *li);

/*
**	PARSING
*/
int		_manage_arg_error_(int ac, char **av);
int		_manage_error_(t_Dlist **stack_a);
int		_check_arg_(int ac, char **av, int type);
int		_check_value_atoi_(long nb);
int		_check_double_(t_Dlist **stack_a);
int		_check_tab_(int *tab, int len);
int		_check_list_ranked_(t_Dlist **stack_a);
int		__free_split_parsing__(char **to_free, int nb_elem);

/*
**	UTILS
*/
int		ft_isdigit(int c);
long	ft_atoi(const char *nptr);
void	ft_putstr(char *str);
int		nb_words(char const *s, char c);
char	**ft_split(char const *s, char c);

/*
**	MOVEMENTS
*/
void	_move_swap_x_(t_Dlist **stack_x, int x);
void	_move_push_x_(t_Dlist **stack_to_move, t_Dlist **stack_x, int x);
void	_move_rotate_x_(t_Dlist **stack_x, int x);
void	_move_reverse_rotate_x_(t_Dlist **stack_x, int x);

/*
**	SORTING
*/
void	__manage_algo__(t_Dlist **stack_a, t_Dlist**stack_b);
int		_pos_compar_three_(t_Dlist **stack_a);
void	_sort_three_(t_Dlist **stack_a);
void	_sort_small_(t_Dlist **stack_a, t_Dlist **stack_b);
void	_is_faster_to_top_(t_Dlist **stack_x, int pos_content, int content);
int		_pos_smallest_(t_Dlist **stack_x);
int		_smallest_(t_Dlist **stack_x);
int		_bigest_(t_Dlist **stack_x);
int		_pos_bigest_(t_Dlist **stack_x);
void	_sort_big_(t_Dlist **stack_a, t_Dlist **stack_b);
void	_push_until_bigest_(t_Dlist **stack_a, t_Dlist **stack_b, int m, int b);
int		_sorting_tab_(int *tab, int len);
int		_get_median_(t_Dlist **stack_a);
void	_is_faster_to_top_big_(t_Dlist **stack_x);
void	_moving_(t_Dlist **stack_a, t_Dlist **stack_b);
void	_get_info_(t_Dlist **stack_a, t_Dlist **stack_b);
void	_attribute_index_(t_Dlist **stack_x);

/*
**	CLEANING
*/
void	__free_basic_int__(int **to_free);
char	**__free_basic_char__(char **to_free, int nb_elem);
void	*_freedel_(t_Dlist **to_free, int print_error);
void	cleaning(t_Dlist **stack_a, t_Dlist **stack_b);

#endif
