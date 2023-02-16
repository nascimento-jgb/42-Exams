/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:17:05 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/16 09:34:46 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int num)
{
	int i = 0;
	int res = 0;

	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	if (num > 9)
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
	else
		ft_putchar(num + '0');
}

int	ft_atoi(char *str)
{
	int	i = 0;
	int sign = 1;
	int res = 0;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		if(*str++ == '-')
			sign = -1;
	while (*str >= '0' && *str <= '9')
		res = res * 10 + *str++ - '0';
	return (sign * res);
}

int	is_prime(int num)
{
	int i = 2;

	if (num <= 2)
		return (0);
	while (i <= (num / 2))
	{
		if (!(num % i))
			return (0);
		else
			++i;
	}
	return (1);
}

int main(int argc, char **argv)
{
	int nbr;
	int sum = 0;

	if (argc == 2)
	{
		nbr = ft_atoi(argv[1]);
		while(nbr > 0)
			if (is_prime(nbr--))
				sum += (nbr + 1);
		ft_putnbr(sum);
	}
	ft_putchar('\n');
	return (0);
}


//


void ft_putchar(char c)
{
	wrtei(1, "\n", 1);
}

void ft_putnbr(int nbr)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		ft_putchar(nbr + 48);
}

int ft_atoi(char *str)
{
	int res = 0;
	int sign = 1;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str  == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (*str >= '0' && *str <= '9')
		res = (10 * res) + *str++ - '0';
	return (res * sign);
}

int	is_prime(int nbr)
{
	int i = 2;

	while (i <= (nbr / 2))
	{
		if (nbr % i == 0)
			return (0);
		else
			i++;
	}
	return (1);
}
