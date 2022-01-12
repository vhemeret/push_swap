/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 01:01:55 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/12 19:05:41 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PUSH_SWAP_H_
# define _PUSH_SWAP_H_

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

/*-----------------------------------*/

/* Structure de maillon */
typedef struct s_list
{
	int	content;
	int index;
	int associate;
	int to_top;
	int to_top_t;
	int	rotation;
	struct s_list	*next;
	struct s_list	*back;
	
}						t_list;

/* Structure de liste */
typedef struct Dlist
{
	int len;
	struct s_list *begin;
	struct s_list *end;
}						Dlist;

/*-----------------------------------*/

/* Prototypes */
void	__print_list__(Dlist *stack_a, Dlist *stack_b, int elem);
int		__create_list__(int nb_elem, char **elem, Dlist **stack_a, int x);

/* list */
int		list_empty(Dlist *li);
int		list_len(Dlist *li);
int		list_begin(Dlist *li);
int		list_end(Dlist *li);
Dlist	*add_back_lst(Dlist **li, int content);
Dlist	*add_front_lst(Dlist **li, int content);
void	__malloc_dlist__(Dlist **li, t_list *new_element);
Dlist	*del_back_list(Dlist *li);
Dlist	*del_front_list(Dlist *li);
void	*_freedel_(Dlist **to_free, int print_error);

/* parsing */
int	_manage_arg_error_(int ac, char **av);
int	_manage_error_(Dlist **stack_a);
int	_check_arg_(int ac, char **av);
int	_check_value_atoi_(long nb);
int	_check_double_(Dlist **stack_a);
int	_check_tab_(int *tab, int len);
int	_check_list_ranked_(Dlist **stack_a);

/* utils */
int		ft_isdigit(int c);
long	ft_atoi(const char *nptr);
void	ft_putstr(char *str);
int		nb_words(char const *s, char c);
char	**ft_split(char const *s, char c);
void	__free_basic_int__(int **to_free);
char	**__free_basic_char__(char **to_free, int nb_elem);
int		ft_lstsize(Dlist **li);

/* sorting */
void	_move_swap_x_(Dlist **stack_x, int x);
void	_move_push_x_(Dlist **stack_to_move, Dlist **stack_x, int x);
void	_move_rotate_x_(Dlist **stack_x, int x);
void	_move_reverse_rotate_x_(Dlist **stack_x, int x);

void	__manage_algo__(Dlist **stack_a, Dlist**stack_b);

int		_pos_compar_three_(Dlist **stack_a);
void	_sort_three_(Dlist **stack_a);
void	_sort_small_(Dlist **stack_a, Dlist **stack_b);

void	_is_faster_to_top_(Dlist **stack_x, int pos_content, int content);
int		_pos_smallest_(Dlist **stack_x);
int		_smallest_(Dlist **stack_x);
int		_bigest_(Dlist **stack_x);
int		_pos_bigest_(Dlist **stack_x);

void	_sort_big_(Dlist **stack_a, Dlist **stack_b);
void	_push_until_bigest_(Dlist **stack_a, Dlist **stack_b, int med, int big);
int		_sorting_tab_(int *tab, int len);
int		_get_median_(Dlist **stack_a);
void	_is_faster_to_top_big_(Dlist **stack_x);
void	_moving_(Dlist **stack_a, Dlist **stack_b);
void	_get_info_(Dlist **stack_a, Dlist **stack_b);
void	_attribute_index_(Dlist **stack_x);

/*-----------------------------------*/

#endif