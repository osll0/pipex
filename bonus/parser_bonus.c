/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokson <seokson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:17:36 by seokson           #+#    #+#             */
/*   Updated: 2025/06/03 17:17:21 by seokson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	escape_char(char c)
{
	if (c == 'n')
		return ('\n');
	if (c == 't')
		return ('\t');
	if (c == 'r')
		return ('\r');
	if (c == 'f')
		return ('\f');
	if (c == 'v')
		return ('\v');
	if (c == '\\')
		return ('\\');
	if (c == '\'')
		return ('\'');
	if (c == '"')
		return ('"');
	return (c);
}

static int	count_tokens(char *s)
{
	int		cnt;
	int		quote_flag;

	cnt = 0;
	quote_flag = 0;
	while (*s)
	{
		while (*s && (*s == ' '))
			s++;
		if (!*s)
			break ;
		cnt++;
		while (*s)
		{
			if (*s == '\'')
				quote_flag ^= 1;
			else if ((*s == ' ') && !quote_flag)
				break ;
			if (*s == '\\' && s[1])
				s++;
			s++;
		}
	}
	return (cnt);
}

static char	*extract_token(char **s)
{
	char	buf[1024];
	int		i;
	int		quote_flag;

	while (**s && (**s == ' '))
		(*s)++;
	i = 0;
	quote_flag = 0;
	while (**s && (quote_flag || !(**s == ' ')))
	{
		if (**s == '\'' && !quote_flag)
			quote_flag = 1;
		else if (**s == '\'' && quote_flag)
			quote_flag = 0;
		else if (**s == '\\' && (*s)[1])
		{
			(*s)++;
			buf[i++] = escape_char(**s);
		}
		else
			buf[i++] = **s;
		(*s)++;
	}
	buf[i] = '\0';
	return (ft_strdup(buf));
}

char	**parse_command(char *cmd)
{
	int		i;
	int		cnt;
	char	**tokens;

	cnt = count_tokens(cmd);
	tokens = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!tokens)
		return (NULL);
	i = 0;
	while (i < cnt)
		tokens[i++] = extract_token(&cmd);
	tokens[i] = NULL;
	return (tokens);
}
