/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:52:38 by vahemere          #+#    #+#             */
/*   Updated: 2021/12/29 23:52:41 by vahemere         ###   ########.fr       */
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
	tmp = NULL;
}

int	_freerror_(t_list *to_free)
{
	t_list	*tmp;

	if (to_free->next)
	{
		while (to_free != NULL)
		{

			tmp = to_free;
			to_free->content = 0;
			to_free = to_free->next;
			free(tmp);
		}
		tmp = NULL;
	}
	else
	{
		free(to_free);
		to_free = NULL;
	}
	printf("Error\n");
	return (0);
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

