/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 07:29:48 by jonascim          #+#    #+#             */
/*   Updated: 2023/03/15 13:09:46 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		aux[j++] = str[i++];
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
	line = push_line(stash);
	stash = update_stash(stash);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

static void	put_char(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
		*len += write(1, str++, 1);
}

static void	put_nbr(long long int nbr, int base, int *len)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nbr < 0)
	{
		nbr *= -1;
		*len += write(1, "-", 1);
	}
	if (nbr >= base)
		put_nbr((nbr / base), base, len);
	*len += write(1, &hex[nbr % base], 1);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	args;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
				put_char(va_arg(args, char *), &len);
			else if (*format == 'd')
				put_nbr((long long int)va_arg(args, int), 10, &len);
			else if (*format == 'x')
				put_nbr((long long int)va_arg(args, unsigned int), 16, &len);
		}
		else
			len += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (len);
}

int	main(int argc, char **argv)
{
	char	*line;
	int		fd;

	line = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while ((line = get_next_line(fd)) > 0)
		{
			ft_printf("%s", line);
			free(line);
			line = NULL;
		}
		free(line);
		line = NULL;
	}
	return (0);
}
