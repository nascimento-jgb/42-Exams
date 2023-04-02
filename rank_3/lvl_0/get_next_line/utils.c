/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 09:56:10 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/02 14:28:51 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i = 0;

	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(char *s, int c)
{
	while (*s)
		if (*s++ == (char)c)
			return (1);
	return (0);
}

void	*ft_calloc(size_t n, size_t size)
{
	char	*ptr;
	size_t	i = 0;

	if (!n || !size)
		return (NULL);
	ptr = (void *)malloc(n * size);
	if (!ptr)
		return (NULL);
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}

char	*ft_strjoin(char *dest, char *orig)
{
	char	*joined;
	char	*temp;

	if (!dest || !orig)
		return (0);
	temp = (char *)malloc(sizeof(char) * (ft_strlen(dest) + ft_strlen(orig)) + 1);
	if (!temp)
		return (NULL);
	joined = temp;
	while (*dest)
		*temp++ = *dest++;
	while (*orig)
		*temp++ = *orig++;
	*temp = '\0';
	return (joined);
}
