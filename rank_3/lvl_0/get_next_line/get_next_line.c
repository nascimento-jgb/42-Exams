/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 07:29:48 by jonascim          #+#    #+#             */
/*   Updated: 2023/03/14 09:45:27 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	ft_strchr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		if (str[i++] == '\n')
			return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *dest, char *orig)
{
	char			*aux;
	unsigned int	len;
	int				i;
	int				j;

	if (!dest && !orig)
		return (NULL);
	len = ft_strlen(dest) + ft_strlen(orig);
	aux = (char *)malloc(sizeof(char) * len + 1);
	if (!aux)
		return (NULL);
	i = 0;
	j = 0;
	if (dest)
	{
		while (dest[i])
			aux[j++] = dest[i++];
		i = 0;
	}
	while (orig[i])
		aux[j++] = orig[i++];
	aux[len] = '\0';
	free((void *)dest);
	return (aux);
}

char	*push_line(char *str)
{
	char	*aux;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	aux = (char *)malloc(sizeof(char) * (i + 1));
	if (!aux)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		aux[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		aux[i] = '\n';
		aux[i + 1] = '\0';
		return (aux);
	}
	aux[i] = '\0';
	return (aux);
}

char	*update_stash(char *str)
{
	char	*aux;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	aux = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!aux)
		return (NULL);
	i++;
	while (str[i])
	{
		aux[j] = str[i];
		j++;
		i++;
	}
	aux[j] = '\0';
	free(str);
	return (aux);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*stash;
	int			counter;

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	counter = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	while (!ft_strchr(buffer) && counter != 0)
	{
		if ((counter = read(fd, buffer, BUFFER_SIZE)) == -1)
			return (NULL);
		buffer[counter] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	buffer = NULL;
	line = push_line(stash);
	stash = update_stash(stash);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

int	main(int argc, char **argv)
{
	char	*line;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	line  = NULL;
	while ((line = get_next_line(fd)) > 0)
	{
		printf("%s", line);
		free(line);
		line = NULL;
	}
	free(line);
	line = NULL;
	return (0);
}
