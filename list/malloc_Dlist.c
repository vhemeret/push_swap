/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_Dlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:20:59 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/11 15:20:59 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	__malloc_dlist__(Dlist **li, t_list *new_element)
{
	*li = malloc(sizeof(Dlist));
	if (!*li)
		return ;
	(*li)->len = 0;
	(*li)->begin = new_element;
	(*li)->end = new_element;
}
