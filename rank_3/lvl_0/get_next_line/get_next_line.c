/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 07:29:48 by jonascim          #+#    #+#             */
/*   Updated: 2023/03/07 10:08:04 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	ft_strchr(char *str)
{
	int	i = 0;

	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i = 0;

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
	int				i = 0;
	int				j = 0;

	if (!orig && !dest)
		return (NULL);
	len = ft_strlen(dest) + ft_strlen(orig);
	aux = (char *)malloc(sizeof(char) * (len + 1));
	if (!aux)
		return (NULL);
	if (dest)
	{
		while (dest[i])
		{
			aux[i] = dest[i];
			i++;
		}
	}
	while (orig[j])
	{
		aux[i] = orig[j];
		j++;
		i++;
	}
	aux[len] = '\0';
	free((void *)dest);
	return (aux);
}

char	*push_line(char *remains)
{
	char	*aux;
	int		i = 0;

	while (remains[i] && remains[i] != '\n')
		i++;
	if (remains[i] == '\n')
		i++;
	aux = (char *)malloc(sizeof(char) * (i + 1));
	if (!aux)
		return (NULL);
	i = 0;
	while (remains[i] && remains[i] != '\n')
	{
		aux[i] = remains[i];
		i++;
	}
	if (remains[i] == '\n')
	{
		aux[i] = '\n';
		aux[i + 1] = '\0';
	}
	else
		aux[i] = '\0';
	return (aux);
}

char	*cut_next_line(char *remains)
{
	char	*aux;
	int		i = 0;
	int		j = 0;

	while (remains[i] && remains[i] != '\n')
		i++;
	if (!remains[i])
	{
		free(remains);
		return (NULL);
	}
	aux = (char *)malloc(sizeof(char) * (ft_strlen(remains) - i + 1));
	if (!aux)
		return (NULL);
	i++;
	while (remains[i])
	{
		aux[j] = remains[i];
		j++;
		i++;
	}
	aux[j] = '\0';
	free(remains);
	return (aux);
}

char	*get_next_line(int fd)
{
	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	static char	*remains;
	char		*line;
	char		buffer[BUFFER_SIZE + 1];
	int			count;

	count = 1;
	buffer[0] = '\0';
	while (!ft_strchr(buffer) && count != 0)
	{
		if ((count = read(fd, buffer, BUFFER_SIZE)) == -1)
			return (NULL);
		buffer[count] = '\0';
		remains = ft_strjoin(remains, buffer);
	}
	line = push_line(remains);
	remains = cut_next_line(remains);
	if (line[0] == '\0')
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

	if (argc != 2 || BUFFER_SIZE <= 1)
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
