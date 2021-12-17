/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:23:18 by vahemere          #+#    #+#             */
/*   Updated: 2021/11/25 15:49:49 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	tmp = *alst;
	if (!new)
		return ;
	else if (!(*alst))
	{
		*alst = new;
		new->next = NULL;
		return ;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next++;
		tmp->next = new;
		new->next = NULL;
	}
}
