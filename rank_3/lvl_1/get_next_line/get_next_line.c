/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 08:10:30 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/23 11:52:15 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdarg.h>

char	*get_next_line(int fd)
{
	int i = 0;
	int bytes;
	char *buffer = malloc(100000);
	char character;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while ((bytes = read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1)) > 0)
	{
		buffer[i++] = character;
		if (character == '\n')
			break ;
	}
	if ((!buffer[i - 1] && !bytes) || bytes == -1)
		return (free(buffer), NULL);
	buffer[i] = '\0';
	return (buffer);
}

void	put_str(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
		*len += write(1, str++, 1);
}

void	put_nbr(long long int nbr, int base, int *len)
{
	char	*hex = "0123456789abcdef";

	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
	}
	if (nbr >= base)
		put_nbr((nbr / base), base, len);
	*len += write(1, &hex[nbr % base], 1);
}

int ft_printf(const char *format, ...)
{
	int len = 0;
	va_list ptr;

	va_start(ptr, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
				put_str(va_arg(ptr, char *), &len);
			else if (*format == 'd')
				put_nbr((long long int)va_arg(ptr, int), 10, &len);
			else if (*format == 'x')
				put_nbr((long long int)va_arg(ptr, unsigned int), 16, &len);
		}
		else
			len += write(1, format, 1);
		format++;
	}
	return (va_end(ptr), len);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		line;
	char	*string;

	line = 1;
	string = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		string = get_next_line(fd);
		while (string != NULL)
		{
			ft_printf("Line %d - %s ", line, string);
			string = get_next_line(fd);
			line++;
		}
		if (!string)
			printf("Line %d - (null) EOF", line);
		close(fd);
	}
	return (0);
}
