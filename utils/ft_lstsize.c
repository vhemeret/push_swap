/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 22:36:53 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/14 00:19:42 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lstsize(t_Dlist **li)
{
	t_list	*tmp_list;
	int		i;

	tmp_list = (*li)->begin;
	i = 0;
	while (tmp_list)
	{
		i++;
		tmp_list = tmp_list->next;
	}
	return (i);
}
