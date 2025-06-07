/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokson <seokson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 20:11:17 by seokson           #+#    #+#             */
/*   Updated: 2025/06/03 17:16:29 by seokson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int ac, char **av, char **envp)
{
	int	status;

	if (ac < 5)
	{
		write(2, "wrong args\n", 11);
		exit(1);
	}
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		if (ac < 6)
		{
			write(2, "wrong args\n", 11);
			exit(1);
		}
		status = run_here_doc_pipex(ac, av, envp);
	}
	else
		status = run_pipex(ac, av, envp);
	exit(status);
}
