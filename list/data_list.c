/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 01:13:35 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/08 01:13:35 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	list_empty(t_Dlist *li)
{
	if (!li)
		return (1);
	return (0);
}

int	list_len(t_Dlist *li)
{
	if (!li)
		return (0);
	return (li->len);
}

int	list_begin(t_Dlist *li)
{
	if (!li)
		return (0);
	return (li->begin->content);
}

int	list_end(t_Dlist *li)
{
	if (!li)
		return (0);
	return (li->end->content);
}
