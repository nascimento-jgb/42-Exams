/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:14:18 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/23 07:50:08 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_char(char *str, char c, int pos)
{
	int	aux = 0;

	while (str[aux] && (aux < pos || pos == -1))
		if (str[aux++] == c)
			return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int	i = 0;

	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (check_char(argv[1], argv[1][i], i) && !check_char(argv[2], argv[1][i], -1))
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
