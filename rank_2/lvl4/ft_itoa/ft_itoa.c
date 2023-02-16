/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:17:27 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/14 10:52:33 by jonascim         ###   ########.fr       */
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


///

long	lencalc(long nb)
{
	int	len = 0;

	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	ft_itoa(int nbr)
{
	char	res;
	int		len;
	long	aux;

	aux = nbr;
	len = ft_lencalc(aux);
}
