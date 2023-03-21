#include "get_next_line.h"
#include <fcntl.h>
#include <stdarg.h>

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
	int		i = 0;

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
	int		lenght = 0;
	va_list	arg;

	va_start(arg, format);
	while (*format)
	{
		if ((*format == '%') && *(format + 1))
		{
			format++;
			if (*format == 's')
				put_str(va_arg(arg, char *), &lenght);
			else if (*format == 'd')
				put_nbr((long long int)va_arg(arg, int), 10, &lenght);
			else if (*format == 'x')
				put_nbr((long long int)va_arg(arg, unsigned int), 16, &lenght);
		}
		else
			lenght += write(1, format, 1);
		format++;
	}
	va_end(arg);
	return (lenght);
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
