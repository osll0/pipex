/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_io_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokson <seokson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 09:08:13 by seokson           #+#    #+#             */
/*   Updated: 2025/07/23 09:22:33 by seokson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	open_infile(char *infile)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd < 0)
	{
		perror(infile);
		exit(1);
	}
	return (fd);
}

int	open_outfile(char *outfile)
{
	int	fd;

	fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror(outfile);
		exit(1);
	}
	return (fd);
}

int	open_outfile_append(char *outfile)
{
	int	fd;

	fd = open(outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
		error_exit("open outfile error", 1);
	return (fd);
}
