/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:03:13 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/02/20 10:45:47 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_b.h"

int	main(int ac, char **av, char **ev)
{
	t_ProcessData	d;
	int				ec;

	if (ac < 5)
	{
		if (ac >= 2 && !ft_strncmp("here_doc", av[1], 9))
			return (ft_disp_err("Usage: ",
					"./pipex here_doc LIMITER cmd1 cmd2 ... cmdn file2.",
					"", 1));
		return (ft_disp_err("Usage: ",
				"./pipex file1 cmd1 cmd2 ... cmdn file2.", "", 1));
	}
	else if (ac < 6 && !ft_strncmp("here_doc", av[1], 9))
		return (ft_disp_err("Usage: ",
				"./pipex here_doc LIMITER cmd1 cmd2 ... cmdn file2.", "", 1));
	if (!ev || ev[0][0] == '\0')
		ft_err_hdl(ft_disp_err("Unexpected error.", "", "", 1), &d);
	d = ft_set_pd(ac, av, ev);
	ec = ft_run_pipe(&d);
	return (ec);
}
