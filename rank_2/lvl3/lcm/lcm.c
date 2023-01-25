/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 09:57:06 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/25 10:07:26 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	lcm(unsigned int a, unsigned int b)
{
	int	lcm = 0;

	if (a == NULL || b == NULL)
		lcm = 0;
	else
	{
		if (a > b)
			lcm = a;
		else
			lcm = b;
		while (lcm % a != 0 && lcm % b != 0)
				lcm += lcm;
	}
	return (lcm);
}
