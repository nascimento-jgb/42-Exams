/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:57:44 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/25 17:07:03 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list *aux;
	int	temp = 0;

	aux = lst;
	while (lst->next != NULL)
	{
		if ((*cmp)(lst->data, lst->next->data) != 0)
			lst = lst->next;
		else
			{
				temp = lst->data;
				lst->data = lst->next->data;
				lst->next->data = temp;
				lst = aux;
			}
	}
	lst = aux;
	return (aux);
}
