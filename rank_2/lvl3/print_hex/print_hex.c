/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:31:28 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/09 10:20:21 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int res = 0;

	while (*str)
		res = 10 * res + *str++ - '0';

	return (res);
}

void	print_hex(int nbr)
{
	char	base[] = "0123456789abcdef";

	if (nbr > 16)
		print_hex (nbr / 16);
	else
		write(1, &base[nbr % 16], 1);
}

int main (int argc, char **argv)
{
	if (argc == 2)
		print_hex(ft_atoi(argv[1]));
	write(1, "\n", 1);
	return (0);
}
