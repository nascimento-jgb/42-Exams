/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 07:46:14 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/25 08:05:24 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	*res;
	int	i = 0;
	int	range = (end - start) + 1;

	res = malloc(sizeof(int *) * range);
	if (!res)
		return(NULL);
	while (i < range)
	{
		if (start < end)
			res[i] = end - i++;
		else
			res[i] = end + i++;
	}
	return (res);
}
