/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 09:57:04 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/04 12:48:16 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*new_buffer(char *dest, char *orig)
{
	char	*temp;

	temp = ft_strjoin(dest, orig);
	free(dest);
	return (temp);
}

char	*get_line(char *buffer)
{
	char	*new_line;
	int		i = 0;

	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	new_line = ft_calloc(i + 1, sizeof(char));
	if (!new_line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		new_line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n' && buffer[i] != '\0')
		new_line[i++] = '\n';
	new_line[i] = '\0';
	return (new_line);
}

char	*update_buffer(char *buffer)
{
	char	*new_buffer;
	char	*aux;
	int		i = 0;

	if (!buffer)
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	i++;
	aux = (char *)malloc(sizeof(char) * ft_strlen(buffer) - i + 1);
	if (!aux)
		return (NULL);
	new_buffer = aux;
	while (buffer[i])
		*aux++ = buffer[i++];
	*aux = '\0';
	free(buffer);
	return (new_buffer);
}

char	*read_buffer(int fd, char *buffer) //, int *flag
{
	char	*buf;
	int		ret;

	if (!buffer)
		buffer = ft_calloc(1, sizeof(char));
	if (!buffer)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while ((ret = read(fd, buf, BUFFER_SIZE)))
	{
		if (ret == -1)
			return (NULL);
		buf[ret] = '\0';
		buffer = new_buffer(buffer, buf);
		// if (ret < BUFFER_SIZE)
		// 	*flag = 1;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buf);
	// if (ret == 0)
	// 	return (NULL);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	// int			flag;

	// flag = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_buffer(fd, buffer); //, &flag
	if (!buffer)
		return (NULL);
	// if (flag == 1)
	// 	return (buffer);
	line = get_line(buffer);
	buffer = update_buffer(buffer);
	return (line);
}
