/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokson <seokson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 10:04:01 by seokson           #+#    #+#             */
/*   Updated: 2025/06/03 17:17:43 by seokson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	error_exit(char *msg, int code)
{
	perror(msg);
	exit(code);
}

void	close_four_fd(int fd1, int fd2, int fd3, int fd4)
{
	if (fd1 >= 0)
		close(fd1);
	if (fd2 >= 0)
		close(fd2);
	if (fd3 >= 0)
		close(fd3);
	if (fd4 >= 0)
		close(fd4);
}

void	fd_error(char *msg, int fd[2], int code)
{
	close_four_fd(fd[0], fd[1], -1, -1);
	error_exit(msg, code);
}

void	free_split_exit(char *msg, char **args, int code)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
	error_exit(msg, code);
}
