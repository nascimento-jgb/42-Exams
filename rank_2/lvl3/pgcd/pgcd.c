/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgdc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:25:56 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/25 10:38:08 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	n1;
	int	n2;
	int	i = 1;

	if (argc == 3)
	{
		n1 = atoi(argv[1]);
		n2 = atoi(argv[2]);
		if (n1 <= 0 || n2 <= 0)
			{
				printf("\n");
				return (0);
			}
		else if (n2 > n1)
			i = n2;
		else
			i = n1;
		while (i >= 1)
		{
			if ( n1 % i == 0 & n2 % i == 0)
				break ;
			else
				--i;
		}
		printf("%d", i);
	}
	printf("\n");
	return (0);
}
