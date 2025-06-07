/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokson <seokson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 09:26:23 by seokson           #+#    #+#             */
/*   Updated: 2025/06/03 17:17:35 by seokson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	run_cmd(int in_fd, int out_fd, char *cmd, char **envp)
{
	char	**cmd_args;
	char	*temp;

	if (dup2(in_fd, STDIN_FILENO) == -1)
		error_exit("duplicate error", 1);
	close(in_fd);
	if (dup2(out_fd, STDOUT_FILENO) == -1)
		error_exit("duplicate error", 1);
	close(out_fd);
	cmd_args = parse_command(cmd);
	if (!cmd_args)
		error_exit("parsing error", 1);
	temp = get_cmd_path(cmd_args[0], envp);
	if (!temp)
		free_split_exit("command not found", cmd_args, 127);
	free(cmd_args[0]);
	cmd_args[0] = temp;
	execve(cmd_args[0], cmd_args, envp);
	free_split_exit("execve error", cmd_args, 1);
}

pid_t	pipe_and_fork(int *prev_fd, char *cmd, char **envp)
{
	int		pipefd[2];
	int		in_fd;
	pid_t	pid;

	if (pipe(pipefd) == -1)
		error_exit("pipe error", 1);
	pid = fork();
	if (pid == -1)
		error_exit("fork error", 1);
	if (pid == 0)
	{
		close(pipefd[0]);
		run_cmd(*prev_fd, pipefd[1], cmd, envp);
	}
	in_fd = *prev_fd;
	*prev_fd = pipefd[0];
	close(in_fd);
	close(pipefd[1]);
	return (pid);
}

pid_t	last_fork(int infile, int outfile, char *cmd, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		error_exit("fork error", 1);
	if (pid == 0)
		run_cmd(infile, outfile, cmd, envp);
	return (pid);
}
