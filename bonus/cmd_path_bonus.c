/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_path_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokson <seokson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:56:04 by seokson           #+#    #+#             */
/*   Updated: 2025/06/03 17:16:59 by seokson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	*get_path_env(char **envp)
{
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
			return (*envp + 5);
		envp++;
	}
	return (NULL);
}

static char	*get_next_path(const char *path, int *i)
{
	int		len;
	char	*dir;
	int		k;

	len = 0;
	while (path[*i + len] && path[*i + len] != ':')
		len++;
	dir = (char *)malloc(len + 2);
	if (!dir)
		return (NULL);
	k = 0;
	while (k < len)
	{
		dir[k] = path[*i + k];
		k++;
	}
	dir[k++] = '/';
	dir[k] = '\0';
	*i += len;
	if (path[*i] == ':')
		(*i)++;
	return (dir);
}

static char	*build_full_path(const char *dir, const char *cmd)
{
	char	*full;

	full = ft_strjoin(dir, cmd);
	if (!full)
		return (NULL);
	return (full);
}

char	*get_cmd_path(char *cmd, char **envp)
{
	char	*path;
	char	*dir;
	char	*full;
	int		i;

	i = 0;
	path = get_path_env(envp);
	if (!path)
		return (NULL);
	while (path[i])
	{
		dir = get_next_path(path, &i);
		if (!dir)
			return (NULL);
		full = build_full_path(dir, cmd);
		free(dir);
		if (!full)
			return (NULL);
		if (access(full, X_OK) == 0)
			return (full);
		free(full);
	}
	return (NULL);
}
