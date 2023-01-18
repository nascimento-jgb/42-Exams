/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:14:45 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/18 08:24:15 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int	res = 0;
	int n1;
	int n2;

	if (argc == 4)
	{
		if (argv[2][0] == '*')
			res = atoi(argv[1]) * atoi(argv[3]);
		else if (argv[2][0] == '+')
			res = atoi(argv[1]) + atoi(argv[3]);
		else if (argv[2][0] == '-')
			res = atoi(argv[1]) - atoi(argv[3]);
		else if (argv[2][0] == '/')
			res = atoi(argv[1]) / atoi(argv[3]);
		else if (argv[2][0] == '%')
			res = atoi(argv[1]) % atoi(argv[3]);
		printf("%d\n", res);
	}
	else
		write(1, "\n", 1);
	return (0);
}
