/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:43:09 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/02/16 19:35:46 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_b.h"

/**
 * @brief Creates pipes for inter-process communication.
 *
 * @param d The process data.
 */
void	ft_mk_pipes(t_ProcessData *d)
{
	int	i;

	i = 0;
	while (i < d->cmd_count - 1)
	{
		if (pipe(d->pipe + 2 * i) == -1)
			ft_err_hdl(ft_disp_err("Could not create pipe", "", "", 1), d);
		i++;
	}
}

/**
 * @brief Closes all pipe file descriptors.
 *
 * @param d The process data.
 */
void	ft_close_pfd(t_ProcessData *d)
{
	int	i;

	i = 0;
	while (i < (d->cmd_count - 1) * 2)
	{
		close(d->pipe[i]);
		i++;
	}
}

/*v1.
if (access(d->cmd_path, F_OK) != 0)
			exit(127);
ft_run_pipe_child*/

/**
 * @brief Runs the child process for a pipe command.
 *
 * @param d The process data.
 */
static void	ft_run_pipe_child(t_ProcessData *d)
{
	if (d->pids[d->child_f] == -1)
		ft_err_hdl(ft_disp_err("fork", ": ", strerror(errno), 1), d);
	else if (d->pids[d->child_f] == 0)
	{
		if (d->cmd_path == NULL || access(d->cmd_path, F_OK) != 0)
			exit(127);
		ft_hdl_chldp(d);
	}
}

/**
 * @brief Runs a pipe command.
 *
 * @param d The process data.
 * @return The exit code of the command.
 */
int	ft_run_pipe(t_ProcessData *d)
{
	int		ec;

	if (pipe(d->pipe) == -1)
		ft_err_hdl(ft_disp_err("pipe", ": ", strerror(errno), 1), d);
	d->child_f = 0;
	while (d->child_f < d->cmd_count)
	{
		d->cmd_opts = ft_split_quotes(d->av[d->child_f + 2 + d->heredoc]);
		if (!d->cmd_opts)
			ft_err_hdl(ft_disp_err("unexpected error", "", "", 1), d);
		d->cmd_path = ft_cmd_path(d->cmd_opts[0], d);
		d->pids[d->child_f] = fork();
		ft_run_pipe_child(d);
		ft_free_s_a(d->cmd_path, d->cmd_opts);
		d->child_f++;
	}
	ec = ft_hdl_prntp(d);
	if (d->heredoc == 1)
		unlink(".heredoc.tmp");
	return (ec);
}
