/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:03:13 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/02/16 16:00:27 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief The main entry point of the program. It sets up the process data,
 *        runs the pipe command, and returns the exit code.
 *
 * @param ac The number of command-line arguments.
 * @param av The array of command-line arguments.
 * @param ev The array of environment variables.
 * @return The exit code of the program.
 */
int	main(int ac, char **av, char **ev)
{
	t_ProcessData	d;
	int				ec;

	if (ac != 5)
	{
		return (ft_disp_err("Usage: ",
				"./nameprogram file1 cmd1 cmd2 file2.", "", 1));
	}
	d = ft_set_pd(ac, av, ev);
	ec = ft_run_pipe(&d);
	return (ec);
}
