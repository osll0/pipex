/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokson <seokson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 21:04:51 by seokson           #+#    #+#             */
/*   Updated: 2025/06/03 17:17:14 by seokson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	run_pipex(int ac, char **av, char **envp)
{
	int		i;
	int		fd[2];
	int		status;
	int		x;
	pid_t	pids[1024];

	i = 2;
	x = 0;
	fd[0] = open_infile(av[1]);
	while (i < ac - 2)
		pids[x] = pipe_and_fork(&fd[0], av[i++], envp);
	fd[1] = open_outfile(av[ac - 1]);
	pids[x++] = last_fork(fd[0], fd[1], av[ac - 2], envp);
	close(fd[0]);
	close(fd[1]);
	if (waitpid(pids[x - 1], &status, 0) == -1)
		error_exit("waitpid error", 1);
	x = 128;
	if (WIFEXITED(status))
		x = WEXITSTATUS(status);
	while (wait(NULL) > 0)
		;
	return (x);
}
