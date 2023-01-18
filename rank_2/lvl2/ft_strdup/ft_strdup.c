/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:08:33 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/18 10:14:08 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strdup(char *src)
{
	int	i = 0;
	char *aux;

	while (src[i])
		i++;
	aux = malloc(sizeof(char *) * i);
	if (!aux)
		return (NULL);
	i = 0;
	while (src[i])
		aux[i] = src[i++];
	aux[i] = '\0';
	return (aux);
}
