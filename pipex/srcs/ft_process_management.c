/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_management.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:13:50 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/02/16 15:58:54 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief Handles child process redirection and execution.
 *
 * @param d The process data.
 */
void	ft_hdl_chldp(t_ProcessData *d)
{
	if (d->child_f == 0)
		ft_redir_io(d->fdi, d->pipe[1], d);
	else if (d->child_f == d->cmd_count - 1)
		ft_redir_io(d->pipe[2 * d->child_f - 2], d->fdo, d);
	else
		ft_redir_io(d->pipe[2 * d->child_f - 2], d->pipe[2 * d->child_f + 1],
			d);
	ft_close_fd(d);
	if (d->cmd_opts == NULL || d->cmd_path == NULL)
		ft_err_hdl(1, d);
	if (execve(d->cmd_path, d->cmd_opts, d->env_vrb) == -1)
		ft_err_hdl(ft_disp_err(d->cmd_opts[0], ": ", strerror(errno), 1), d);
}

/**
 * @brief Handles parent process, waits for children and collects exit codes.
 *
 * @param d The process data.
 * @return The exit code of the last child process.
 */
int	ft_hdl_prntp(t_ProcessData *d)
{
	pid_t	wpid;
	int		status;
	int		exit_code;

	ft_close_fd(d);
	d->child_f--;
	exit_code = 1;
	while (d->child_f >= 0)
	{
		wpid = waitpid(d->pids[d->child_f], &status, 0);
		if (wpid == d->pids[d->cmd_count - 1])
		{
			if ((d->child_f == (d->cmd_count - 1)) && WIFEXITED(status))
				exit_code = WEXITSTATUS(status);
		}
		d->child_f--;
	}
	free(d->pipe);
	free(d->pids);
	return (exit_code);
}
