/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:15:24 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/18 10:21:12 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strpbk(const char *s1, const char *s2)
{
	int i = 0;

	if (!s1 || *s2)
		return (0);
	while (*s1)
	{
		while (s2[i])
			if (*s1 == s2[i++])
				return ((char *)s1);
		s1++;
	}
	return (0);
}
