/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokson <seokson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 12:05:27 by seokson           #+#    #+#             */
/*   Updated: 2025/06/03 17:19:17 by seokson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include "../libft/libft.h"

char	*get_cmd_path(char *cmd, char **envp);

void	error_exit(char *msg, int code);
void	close_four_fd(int fd1, int fd2, int fd3, int fd4);
void	fd_error(char *msg, int fd[2], int code);
void	free_split_exit(char *msg, char **args, int code);

pid_t	pipe_and_fork(int *prev_fd, char *cmd, char **envp);
pid_t	last_fork(int infile, int outfile, char *cmd, char **envp);

int		open_infile(char *infile);
int		open_outfile(char *outfile);
int		open_outfile_append(char *outfile);

char	**parse_command(char *cmd);

int		run_pipex(int ac, char **av, char **envp);

int		run_here_doc_pipex(int ac, char **av, char **envp);

#endif
