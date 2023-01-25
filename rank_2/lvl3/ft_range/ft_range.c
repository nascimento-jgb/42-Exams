/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 07:35:57 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/25 07:44:30 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	*pad;
	int	i = 0;
	int	range = (end - start) + 1;

	pad = malloc(sizeof(int *) * range);
	if (!pad)
		return (NULL);
	while (i < range)
		pad[i] = start + i++;
	return (pad);
}
