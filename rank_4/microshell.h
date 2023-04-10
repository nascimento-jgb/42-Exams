/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 08:26:33 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/10 08:26:36 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICROSHELL_H
# define MICROSHELL_H

# include <string.h>
# include <unistd.h>
# include <sys/wait.h>

int	error_msg(char *str, char *argv);
int	exec_cmd(char **argv, int i, int temp_fd, char **envp);

#endif
