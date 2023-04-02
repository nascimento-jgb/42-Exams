/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:30:41 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/02 14:28:50 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>


int	main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		i;

	line = NULL;
	if (argc == 2)
	{
		i = 0;
		fd = open(argv[1], O_RDONLY);
		while ((line = get_next_line(fd)) != NULL)
		{
			i++;
			printf("%s", line);
			free(line);
			line = NULL;
		}
		// line = get_next_line(fd);
		// printf("%s", line);
		// free(line);
		// line = NULL;
		// line = get_next_line(fd);
		// printf("%s", line);
		// free(line);
		// line = NULL;
		// line = get_next_line(fd);
		// printf("%s", line);
		// free(line);
		// line = NULL;
		// line = get_next_line(fd);
		// printf("%s", line);
		// free(line);
		// line = NULL;
		// line = get_next_line(fd);
		// printf("%s", line);
		free(line);
		line = NULL;
		// line = get_next_line(fd);
		// printf("%s", line);
		// free(line);
		// line = NULL;
		printf("\n");
		printf("%d", i);
	}
	return (0);
}
