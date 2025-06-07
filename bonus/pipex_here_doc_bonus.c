/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_here_doc_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokson <seokson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:14:35 by seokson           #+#    #+#             */
/*   Updated: 2025/06/03 17:19:36 by seokson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	write_heredoc_input(char *limiter, int outfile)
{
	char	*line;
	size_t	lim_len;

	lim_len = ft_strlen(limiter);
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (ft_strncmp(line, limiter, lim_len) == 0 && line[lim_len] == '\n')
		{
			free(line);
			break ;
		}
		write(outfile, line, ft_strlen(line));
		free(line);
	}
}

int	run_here_doc_pipex(int ac, char **av, char **envp)
{
	int		heredoc_pipe[2];
	int		fd[2];
	int		i;

	if (pipe(heredoc_pipe) == -1)
		error_exit("pipe error", 1);
	write_heredoc_input(av[2], heredoc_pipe[1]);
	close(heredoc_pipe[1]);
	fd[0] = heredoc_pipe[0];
	i = 3;
	while (i < ac - 2)
		pipe_and_fork(&fd[0], av[i++], envp);
	fd[1] = open_outfile_append(av[ac - 1]);
	last_fork(fd[0], fd[1], av[ac - 2], envp);
	close(fd[0]);
	close(fd[1]);
	while (--ac > 4)
		wait(NULL);
	return (0);
}
