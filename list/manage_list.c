/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 01:21:56 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/08 01:21:56 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

Dlist	*add_back_lst(Dlist **li, int content)
{
	t_list	 *new_element;

	new_element = malloc(sizeof(t_list));
	if (!new_element)
		return (NULL);
	new_element->content = content;
	new_element->next = NULL;
	new_element->back = NULL;
	if (!(*li))
	{
		*li = malloc(sizeof(Dlist));
		if (!li)
			return (NULL);
		(*li)->len = 0;
		(*li)->begin = new_element;
		(*li)->end = new_element;
	}
	else
	{
		(*li)->end->next = new_element;
		new_element->back = (*li)->end;
		(*li)->end = new_element;
	}
	(*li)->len += 1;
	return (*li);
}

Dlist	*add_front_lst(Dlist **li, int content)
{
	t_list	*new_element;

	new_element = malloc(sizeof(t_list));
	if (!new_element)
		return (NULL);
	new_element->content = content;
	new_element->next = NULL;
	new_element->back = NULL;
	if (!(*li))
	{
		*li = malloc(sizeof(Dlist));
		if (!*li)
			return (NULL);
		(*li)->len = 0;
		(*li)->begin = new_element;
		(*li)->end = new_element;
	}
	else
	{
		(*li)->begin->back = new_element;
		new_element->next = (*li)->begin;
		(*li)->begin = new_element;
	}
	(*li)->len += 1;
	return (*li);
}

Dlist	*del_back_list(Dlist *li)
{
	t_list	*tmp_list;

	if (!li)
		return (NULL);
	if (li->begin == li->end)
	{
		free(li->begin);
		li->begin = NULL;
		free(li);
		li = NULL;
		return (NULL);
	}
	tmp_list = li->end;
	li->end = li->end->back;
	li->end->next = NULL;
	tmp_list->next = NULL;
	tmp_list->back = NULL;
	free(tmp_list);
	tmp_list = NULL;
	li->len -= 1;
	return (li);
}

Dlist	*del_front_list(Dlist *li)
{
	t_list	*tmp_list;

	if (!li)
		return (NULL);
	if (li->begin == li->end)
	{
		free(li);
		li = NULL;
		return (NULL);
	}
	tmp_list = li->begin;
	li->begin = li->begin->next;
	li->begin->back = NULL;
	tmp_list->next = NULL;
	tmp_list->back = NULL;
	free(tmp_list);
	tmp_list = NULL;
	li->len -= 1;
	return (li);
}
