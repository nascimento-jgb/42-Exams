/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:21:41 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/18 14:09:54 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_char(char *s, char c, int len)
{
	int	aux = 0;

	while (s[aux] && (aux < len || len == -1))
		if (s[aux++] == c)
			return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i = 0;

	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (!check_char(argv[1], argv[1][i], i) && check_char(argv[2], argv[1][i], -1))
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
