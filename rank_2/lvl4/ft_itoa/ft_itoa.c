/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:17:27 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/16 09:55:10 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	lenght(long nbr)
{
	int	aux;

	aux = 0;

	if (nbr < 0)
	{
		aux++;
		nbr *= -1;
	}
	while (nbr)
	{
		aux++;
		nbr /= 10;
	}
	return (aux);
}

char	*ft_itoa(int nbr)
{
	char	*res;
	long	temp;
	int		len;

	temp = nbr;
	len = lenght(temp);
	res = malloc(sizeof(char *) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (temp < 0)
	{
		res[0] = '-';
		temp *= -1;
	}
	if (temp == 0)
	{
		res[0] = '0';
		return (res);
	}
	while (temp)
	{
		res[--len] = (temp % 10) + '0';
		temp /= 10;
	}
	return (res);
}

// int	main(void)
// {
// 	printf("%s\n", ft_itoa(0));
// 	return (0);
// }