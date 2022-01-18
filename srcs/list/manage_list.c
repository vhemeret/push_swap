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

#include "../../push_swap.h"

t_Dlist	*add_back_lst(t_Dlist **li, int content)
{
	t_list	*new_element;

	new_element = malloc(sizeof(t_list));
	if (!new_element)
		return (NULL);
	new_element->content = content;
	new_element->index = 0;
	new_element->associate = 0;
	new_element->to_top = 0;
	new_element->to_top_t = 0;
	new_element->rotation = 0;
	new_element->next = NULL;
	new_element->back = NULL;
	if (!(*li))
		__malloc_t_dlist__(li, new_element);
	else
	{
		(*li)->end->next = new_element;
		new_element->back = (*li)->end;
		(*li)->end = new_element;
	}
	(*li)->len += 1;
	return (*li);
}

t_Dlist	*add_front_lst(t_Dlist **li, int content)
{
	t_list	*new_element;

	new_element = malloc(sizeof(t_list));
	if (!new_element)
		return (NULL);
	new_element->content = content;
	new_element->index = 0;
	new_element->associate = 0;
	new_element->to_top = 0;
	new_element->to_top_t = 0;
	new_element->rotation = 0;
	new_element->next = NULL;
	new_element->back = NULL;
	if (!(*li))
		__malloc_t_dlist__(li, new_element);
	else
	{
		(*li)->begin->back = new_element;
		new_element->next = (*li)->begin;
		(*li)->begin = new_element;
	}
	(*li)->len += 1;
	return (*li);
}

t_Dlist	*del_back_list(t_Dlist *li)
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

t_Dlist	*del_front_list(t_Dlist *li)
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
