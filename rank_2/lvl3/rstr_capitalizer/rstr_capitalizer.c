/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:40:57 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/25 10:57:23 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rstr_capitalizer(char *str)
{
	int	i = 0;

	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
		if ((str[i + 1] == '\0' || str[i + 1] == ' ' || str[i + 1] == '\t') && (str[i] >= 97 && str[i] <= 122))
			str[i] -= 32;
		write(1, &str[i++], 1);
	}
}
int	main(int argc, char **argv)
{
	int	j = 1;

	if (argc == 1)
		write(1, "\n", 1);
	else
	{
		while (j < argc)
		{
			rstr_capitalizer(argv[j++]);
			write(1, "\n", 1);
		}
	}
	return (0);
}
