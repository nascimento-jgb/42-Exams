/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 08:26:41 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/10 11:36:24 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

int	error_msg(char *str, char *argv)
{
	while (str && *str)
		write(2, str++, 1);
	if (argv)
		while (*argv)
			write(2, argv++, 1);
	write(2, "\n", 1);
	return (1);
}

int	exec_cmd(char **argv, int i, int temp_fd, char **envp)
{
	argv[i] = NULL;
	dup2(temp_fd, STDIN_FILENO);
	close(temp_fd);
	execve(argv[0], argv, envp);
	return (error_msg("error: cannot execute ", argv[0]));
}


int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	fd[2];
	int	temp_fd;
	(void)argc;

	i = 0;
	temp_fd = dup(STDIN_FILENO);
	while (argv[i] && argv[i + 1])
	{
		argv = &argv[i + 1];
		i = 0;
		while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
			i++;
		if (strcmp(argv[0], "cd") == 0)
		{
			if (i != 2)
				error_msg("error: cd: bad arguments", NULL);
			else if (chdir(argv[1]) != 0)
				error_msg("error: cd: cannot change directory to ", argv[1]);
		}
		else if (i != 0 && (argv[i] == NULL || strcmp(argv[i], ";") == 0))
		{
			if (fork() == 0)
			{
				if (exec_cmd(argv, i, temp_fd, envp))
					return (1);
			}
			else
			{
				close(temp_fd);
				while (waitpid(-1, NULL, WUNTRACED) != -1)
					;
				temp_fd = dup(STDIN_FILENO);
			}
		}
		else if (i != 0 && strcmp(argv[i], "|") == 0)
		{
			pipe(fd);
			if (fork() == 0)
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
				if (exec_cmd(argv, i, temp_fd, envp))
					return (1);
			}
			else
			{
				close(fd[1]);
				close(temp_fd);
				temp_fd = fd[0];
			}
		}
	}
	close(temp_fd);
	return (0);
}
