/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:26:34 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/18 10:49:27 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	ft_strrev(char *str)
{
	int		len;
	int		i;
	char	c;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	while (--len > i++)
	{
		c = str[len];
		str[len] = str[i];
		str[i] = c;
	}
	return (str);
}
