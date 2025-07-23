/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokson <seokson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 21:04:51 by seokson           #+#    #+#             */
/*   Updated: 2025/07/23 01:58:52 by seokson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	run_pipex(int ac, char **av, char **envp)
{
	int		i;
	int		fd[2];
	int		status;
	pid_t	last_pid;

	i = 2;
	fd[0] = open_infile(av[1]);
	while (i < ac - 2)
		pipe_and_fork(&fd[0], av[i++], envp);
	fd[1] = open_outfile(av[ac - 1]);
	last_pid = last_fork(fd[0], fd[1], av[ac - 2], envp);
	close(fd[0]);
	close(fd[1]);
	if (waitpid(last_pid, &status, 0) == -1)
		error_exit("waitpid error", 1);
	while (wait(NULL) > 0)
		;
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (128);
}
