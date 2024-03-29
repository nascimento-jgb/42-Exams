/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:50:59 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/04 10:42:50 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


void	put_str(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
		*len += write(1, str++, 1);
}

void	put_nbr(long long int nbr, int base, int *len)
{
	char	*hexa = "0123456789abcdef";

	if (nbr < 0)
	{
		nbr *= -1;
		*len += write(1, "-", 1);
	}
	if (nbr >= base)
		put_nbr((nbr / base), base, len);
	*len += write(1, &hexa[nbr % base], 1);
}

int	ft_printf(const char *format, ...)
{
	int		len = 0;
	va_list	ptr;

	va_start(ptr, format);
	while (*format)
	{
		if (*format == '%' && *format + 1)
		{
			format++;
			if (*format == 's')
				put_str(va_arg(ptr, char *), &len);
			else if (*format == 'd')
				put_nbr((long long int)va_arg(ptr, int), 10, &len);
			else if (*format == 'x')
				put_nbr((long long int)va_arg(ptr, unsigned int), 16, &len);
			// else if (*format == '%')
			// 	len += write(1, format, 1);
		}
		else
			len += write(1, format, 1);
		format++;
	}
	return (va_end(ptr), len);
}

int	main(void)
{
	int	size;
	size = 0;
	size = ft_printf("%s\n", "toto");
	printf("%d\n", size);
	size = printf("%s\n", "toto");
	printf("%d\n", size);
	size = ft_printf("Magic %s is %d\n", "number", 42);
	printf("%d\n", size);
	size = printf("Magic %s is %d\n", "number", 42);
	printf("%d\n", size);
	size = ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("%d\n", size);
	size = printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("%d\n", size);
	size = ft_printf("%d %d %x\n", INT_MAX, INT_MIN, UINT_MAX);
	printf("%d\n", size);
	size = printf("%d %d %x\n", INT_MAX, INT_MIN, UINT_MAX);
	printf("%d\n", size);
	size = ft_printf("%d, %d\n", 0, -24);
	printf("%d\n", size);
	size = printf("%d, %d\n", 0, -24);
	printf("%d\n", size);
	size = ft_printf("Hello world %%\n");
	printf("%d\n", size);
	size = printf("Hello world %%\n");
	printf("%d\n", size);
	size = ft_printf(" \n");
	printf("%d\n", size);
	size = printf(" \n");
	printf("%d\n", size);
	size = ft_printf("%s\n", NULL);
	printf("%d\n", size);
	size = printf("%s\n", NULL);
	printf("%d\n", size);
	return (0);
}
