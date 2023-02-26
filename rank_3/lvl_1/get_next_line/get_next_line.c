/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 08:10:30 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/26 15:52:23 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static int ft_strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		++i;
	return (i);
}

static char	*ft_strdup(char *str)
{
	int i = 0;
	char *dest = malloc(sizeof(char) * (ft_strlen(str) + 1));

	if (!dest)
		return NULL;
	while (str[i] != '\0')
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
	if (!(dest = (char *)malloc(i + 2)))
		return (NULL);
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
	char	buf;
	char	*line;
	int		ret;
	int		i;

	if (fd < 0)
		return (NULL);
	line = ft_strdup("");
	while ((ret = read(fd, &buf, 1)) > 0)
	{
		line = ft_strjoin(line, buf);
		if (buf == '\n')
			break ;
	}
	i = 0;
	while (line[i])
		i++;
	if (i == 0)
	{
		free(line);
		line = NULL;
	}
	if (ret == -1)
	{
		free(line);
		line = NULL;
	}
	return (line);
}
// int	ft_strlen(char *str)
// {
// 	int	i = 0;

// 	if (!str)
// 		return (0);
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strjoin(char *remains, char *buffer)
// {
// 	int				i = 0;
// 	int				j = 0;
// 	unsigned int	size;
// 	char			*array;

// 	if (!remains && !buffer)
// 		return (NULL);
// 	size = ft_strlen(remains) + ft_strlen(buffer);
// 	array = (char *)malloc(sizeof(char) * (size + 1));
// 	if (!array)
// 		return (NULL);
// 	if (remains)
// 	{
// 		while (remains[i])
// 			array[j++] = remains[i++];
// 		i = 0;
// 	}
// 	while (buffer[i])
// 		array[j++] = buffer[i++];
// 	array[size] = '\0';
// 	free((void *)remains);
// 	return (array);
// }

// bool ft_strchr(char *line)
// {
// 	int i = 0;
// 	while (line[i])
// 		if (line[i++] == '\n')
// 			return (true);
// 	return (false);
// }

// char	*push_line(char *remains)
// {
// 	int		i = 0;
// 	char	*temp;

// 	while (remains[i] && remains[i] != '\n')
// 		i++;
// 	if (remains[i] == '\n')
// 		i++;
// 	if (!(temp = (char *)malloc(sizeof(char) * (i + 1))))
// 		return (NULL);
// 	i = 0;
// 	while (remains[i] && remains[i] != '\n')
// 	{
// 		temp[i] = remains[i];
// 		i++;
// 	}
// 	if (remains[i] == '\n')
// 	{
// 		temp[i] = '\n';
// 		temp[i + 1] = '\0';
// 		return (temp);
// 	}
// 	temp[i] = '\0';
// 	return (temp);
// }

// char	*cut_next_line(char *remains)
// {
// 	int		i = 0;
// 	int		j = 0;
// 	char	*temp;

// 	while (remains[i] && remains[i] != '\n')
// 		i++;
// 	if (!remains[i])
// 		return (free(remains), NULL);
// 	if (!(temp = (char *)malloc(sizeof(char) * (ft_strlen(remains) - i + 1))))
// 		return (NULL);
// 	i++;
// 	while (remains[i])
// 	{
// 		temp[j] = remains[i];
// 		i++;
// 		j++;
// 	}
// 	temp[j] = '\0';
// 	return (temp);
// }

// char	*get_next_line(int fd)
// {
// 	int			count = 1;
// 	static char	*remains;
// 	char		*line;
// 	char		buffer[BUFFER_SIZE + 1];

// 	buffer[0] = '\0';
// 	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	while (!ft_strchr(buffer) && count != 0)
// 	{
// 		if ((count = read(fd, buffer, BUFFER_SIZE)) == -1)
// 			return (NULL);
// 		buffer[count] = '\0';
// 		remains = ft_strjoin(remains, buffer);
// 	}
// 	line = push_line(remains);
// 	remains = cut_next_line(remains);
// 	if (line[0] == '\0')
// 		return (free(line), NULL);
// 	return (line);
// }

// void	put_str(char *str, int *len)
// {
// 	if (!str)
// 		str = "(null)";
// 	while (*str)
// 		*len += write(1, str++, 1);
// }

// void	put_nbr(long long int nbr, int base, int *len)
// {
// 	char	*hex = "0123456789abcdef";

// 	if (nbr < 0)
// 	{
// 		nbr *= -1;
// 		write(1, "-", 1);
// 	}
// 	if (nbr >= base)
// 		put_nbr((nbr / base), base, len);
// 	*len += write(1, &hex[nbr % base], 1);
// }

// int ft_printf(const char *format, ...)
// {
// 	int len = 0;
// 	va_list ptr;

// 	va_start(ptr, format);
// 	while (*format)
// 	{
// 		if (*format == '%')
// 		{
// 			format++;
// 			if (*format == 's')
// 				put_str(va_arg(ptr, char *), &len);
// 			else if (*format == 'd')
// 				put_nbr((long long int)va_arg(ptr, int), 10, &len);
// 			else if (*format == 'x')
// 				put_nbr((long long int)va_arg(ptr, unsigned int), 16, &len);
// 		}
// 		else
// 			len += write(1, format, 1);
// 		format++;
// 	}
// 	return (va_end(ptr), len);
// }

int main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc != 2 || BUFFER_SIZE < 1)
		return (0);
	fd = open(argv[1], O_RDONLY);
	line = NULL;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	free(line);
	line = NULL;
	close(fd);
	return (0);
}
