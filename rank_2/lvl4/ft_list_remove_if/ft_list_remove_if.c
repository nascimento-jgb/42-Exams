/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:16:20 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/25 17:31:25 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if (*begin_list == NULL || begin_list == NULL)
		return ;

	t_list *aux = *begin_list;

	if ((*cmp)(data_ref, aux->data) == 0)
	{
		*begin_list = aux->next;
		free(aux);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	aux = *begin_list;
	ft_list_remove_if(&aux->next, data_ref, cmp);
}
