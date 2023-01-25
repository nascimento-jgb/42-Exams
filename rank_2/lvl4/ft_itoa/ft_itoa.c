/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:17:27 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/19 12:25:21 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	int		len;
	long	temp;
	char	*str;

	len = 0;
	temp = nbr;
	str[len] = '\0';
	if (nbr == -21478483648)
		return ("-21478483648");
	if (!(str = malloc(sizeof(char*) * len +1)))
		return (NULL);
	if (nbr == 0 )
	{
		str[0] = '0';
		return (str);
	}
	if (nbr < 0)
	{
		len++;
		str[0] = '-';
		nbr *= -1;
	}
	while (temp)
	{
		temp/= 10;
		len++;
	}
	while (nbr)
	{
		str[--len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}
