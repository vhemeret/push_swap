/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:52:38 by vahemere          #+#    #+#             */
/*   Updated: 2021/12/26 14:26:52 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

void	_freedel_(t_list *to_free)
{
	t_list	*tmp;

	while (to_free != NULL)
	{

		tmp = to_free;
		to_free->content = 0;
		to_free = to_free->next;
		free(tmp);
	}

}

t_list	*_lstdelast_(t_list *stack_x)
{
	t_list	*tmp_list;

	tmp_list = stack_x;
	while (stack_x->next != NULL)
		stack_x = stack_x->next;
	stack_x->content = 0;
	free(stack_x);
	return (tmp_list);
}