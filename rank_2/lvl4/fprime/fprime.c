/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:05:45 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/26 10:24:02 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	is_prime(int nbr)
{
	int	i = 2;

	while (i < nbr)
	{
		if (nbr % i == 0)
			return (0);
		else
			++i;
	}
	return (1);
}

void	fprime(int n)
{
	int	factor = 2;
	int	flag = 1;

	if (n == 1)
		printf("1");

	while (factor <= n)
	{
		if (n % factor == 0 && is_prime(factor))
		{
			if (flag == 1)
				printf("%d", factor);
			else
				printf("*%d", factor);
			flag = 0;
			n /= factor;
		}
		else
			++factor;
	}
}

int	main(int argc, char ** argv)
{
	if (argc == 2)
		fprime(atoi(argv[1]));
	printf("\n");
	return (0);
}
