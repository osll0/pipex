/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokson <seokson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 20:11:17 by seokson           #+#    #+#             */
/*   Updated: 2025/05/30 18:20:36 by seokson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int	status;

	if (ac != 5)
	{
		write(2, "wrong args\n", 11);
		exit(1);
	}
	status = run_pipex(ac, av, envp);
	exit(status);
}
