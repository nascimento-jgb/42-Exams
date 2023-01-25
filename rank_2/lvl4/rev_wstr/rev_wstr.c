/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:35:21 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/25 16:25:16 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_word(char *str, int start, int end)
{
	while (start <= end)
		ft_putchar(str[start++]);
}

int	main(int argc, char **argv)
{
	int i = 0;
	int	end = 0;
	int	start = 0;

	if (argc == 2)
	{
		while (argv[1][i])
			i++;
		while (i >= 0)
		{
			while (argv[1][i] == '\0' || argv[1][i] == ' ' || argv[1][i] == '\t')
				i--;
			end = i;
			while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
				i--;
			start = i + 1;
			print_word(argv[1], start, end);
			if (start != 0)
				ft_putchar(' ');
			i--;
		}
	}
	ft_putchar('\n');
	return (0);
}
