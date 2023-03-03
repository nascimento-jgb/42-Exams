/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 08:10:30 by jonascim          #+#    #+#             */
/*   Updated: 2023/03/03 11:51:42 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static char	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*ft_strdup(char *str)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!dest)
	{
		free(dest);
		return (NULL);
	}
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*ft_strjoin(char *str, char c)
{
	char	*dest;
	int		i;

	i = 0;
	while (str[i])
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 2));
	if (!dest)
		return (free(dest), NULL);
	i = 0;
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = c;
	dest[i + 1] = '\0';
	free(str);
	return (dest);
}

char	*get_next_line(int fd)
{
	char		buffer;
	static char	*line;
	int			bytes;
	int			i;

	i = 0;
	bytes = 1;
	if (fd < 0)
		return (NULL);
	line = ft_strdup("");
	while (bytes > 0)
	{
		bytes = read(fd, &buffer, BUFFER_SIZE - BUFFER_SIZE + 1);
		line = ft_strjoin(line, buffer);
		if (buffer == '\n')
			break ;
	}
	while (line[i])
		i++;
	if (i == 0 || bytes == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*rline;

	if (argc != 2 || BUFFER_SIZE < 1)
		return (1);
	fd = open(argv[1], O_RDONLY);
	rline = NULL;
	while ((rline = get_next_line(fd)) != NULL)
	{
		printf("%s", rline);
		free(rline);
		rline = NULL;
	}
	free(rline);
	rline = NULL;
	return (0);
}
