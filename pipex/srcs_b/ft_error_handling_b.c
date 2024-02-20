/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handling_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:55:11 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/02/18 11:53:22 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_b.h"

/**
 * @brief Handles errors by cleaning up and exiting the program.
 *
 * @param es The exit status to use when exiting the program.
 * @param d The process data.
 */
void	ft_err_hdl(int es, t_ProcessData *d)
{
	if (d)
	{
		ft_close_fd(d);
		if (d->pipe != NULL)
			free(d->pipe);
		if (d->pids != NULL)
			free(d->pids);
		if (d->cmd_opts != NULL || d->cmd_path != NULL)
			ft_free_s_a(d->cmd_path, d->cmd_opts);
	}
	if (d->heredoc == 1)
		unlink(".heredoc.tmp");
	exit(es);
}

/**
 * @brief Displays an error message.
 *
 * @param e1 The first part of the error message.
 * @param e2 The second part of the error message.
 * @param e3 The third part of the error message.
 * @param es The exit status to return.
 * @return The exit status.
 * if you will run pipex on linux, pls add:
 * ft_putstr_fd("pipex: ", 2);
 * ft_putstr_fd("line 1: ", 2);
 * ft_putstr_fd(e1, 2);
 */
int	ft_disp_err(char *e1, char *e2, char *e3, int es)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(e1, 2);
	ft_putstr_fd(e2, 2);
	ft_putendl_fd(e3, 2);
	return (es);
}
