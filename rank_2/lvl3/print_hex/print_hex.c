/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:31:28 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/07 15:25:48 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int res	= 0;

	while (*str)
		res = 10 * res + *str++ - '0';
	return (res);
}

void	print_hex(int n)
{
	char	hex_str[] = "01234567890abcdef";

	if (n >= 16)
		print_hex(n/16);
	else
		write(1, &hex_str[n % 16], 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		print_hex(ft_atoi(argv[1]));
	write(1, "\n", 1);
	return (0);
}
