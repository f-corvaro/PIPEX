/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:04:13 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/02/16 15:56:10 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief Initializes a t_ProcessData structure.
 *
 * @return An initialized t_ProcessData structure.
 */
static	t_ProcessData	ft_init_pd(void)
{
	t_ProcessData	d;

	d.ac = -1;
	d.fdi = -1;
	d.fdo = -1;
	d.heredoc = 0;
	d.cmd_count = -1;
	d.child_f = -1;
	d.av = NULL;
	d.env_vrb = NULL;
	d.pipe = NULL;
	d.pids = NULL;
	d.cmd_opts = NULL;
	d.cmd_path = NULL;
	return (d);
}

/**
 * @brief Sets up a t_ProcessData structure with given parameters.
 *
 * @param ac The argument count.
 * @param av The argument vector.
 * @param ev The environment variables.
 * @return A set up t_ProcessData structure.
 */
t_ProcessData	ft_set_pd(int ac, char **av, char **ev)
{
	t_ProcessData	d;

	d = ft_init_pd();
	d.env_vrb = ev;
	d.ac = ac;
	d.av = av;
	if (!ft_strncmp("here_doc", av[1], 9))
		d.heredoc = 1;
	ft_open_in(&d);
	ft_open_out(&d);
	d.cmd_count = ac - 3 - d.heredoc;
	d.pids = malloc(sizeof * d.pids * d.cmd_count);
	if (!d.pids)
		ft_err_hdl(ft_disp_err("PID error", strerror(errno), "", 1), &d);
	d.pipe = malloc(sizeof * d.pipe * 2 * (d.cmd_count - 1));
	if (!d.pipe)
		ft_err_hdl(ft_disp_err("Pipe error", "", "", 1), &d);
	ft_mk_pipes(&d);
	return (d);
}
