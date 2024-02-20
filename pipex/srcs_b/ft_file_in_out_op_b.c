/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_in_out_op_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:57:21 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/02/16 19:34:30 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_b.h"

/**
 * @brief Handles the heredoc input redirection.
 *
 * @param d The process data.
 */
void	ft_hdoc_hdl(t_ProcessData *d)
{
	int		tfd;
	int		sfd;
	char	*ln;

	tfd = open(".heredoc.tmp", O_CREAT | O_WRONLY | O_TRUNC, FILE_PERMISSIONS);
	sfd = dup(STDIN_FILENO);
	if (tfd == -1)
		ft_err_hdl(ft_disp_err("here_doc", ": ", strerror(errno), 1), d);
	ln = "";
	while (1)
	{
		ft_putstr_fd("here_doc > ", 1);
		ln = get_next_line(sfd);
		if (ln == NULL)
			break ;
		if (ft_strlen(d->av[2]) + 1 == ft_strlen(ln)
			&& !ft_strncmp(ln, d->av[2], ft_strlen(d->av[2] + 1)))
			close(sfd);
		else
			ft_putstr_fd(ln, tfd);
		free(ln);
	}
	close(tfd);
}

/**
 * @brief Opens the input file or heredoc.
 *
 * @param d The process data.
 */
void	ft_open_in(t_ProcessData *d)
{
	if (d->heredoc == 1)
	{
		ft_hdoc_hdl(d);
		d->fdi = open(".heredoc.tmp", O_RDONLY);
		if (d->fdi == -1)
			ft_err_hdl(ft_disp_err("here_doc", ": ", strerror(errno), 1), d);
	}
	else
	{
		d->fdi = open(d->av[1], O_RDONLY, FILE_PERMISSIONS);
		if (d->fdi == -1)
			ft_disp_err(d->av[1], ": ", strerror(errno), 1);
	}
}

/**
 * @brief Opens the output file.
 *
 * @param d The process data.
 */
void	ft_open_out(t_ProcessData *d)
{
	if (d->heredoc == 1)
		d->fdo = open(d->av[d->ac - 1], O_WRONLY | O_CREAT
				| O_APPEND, FILE_PERMISSIONS);
	else
		d->fdo = open(d->av[d->ac - 1], O_WRONLY | O_CREAT
				| O_TRUNC, FILE_PERMISSIONS);
	if (d->fdo == -1)
		ft_disp_err(d->av[d->ac - 1], ": ", strerror(errno), 1);
}

/**
 * @brief Redirects the standard input and output.
 *
 * @param in The file descriptor for input.
 * @param out The file descriptor for output.
 * @param d The process data.
 */
void	ft_redir_io(int in, int out, t_ProcessData *d)
{
	if (dup2(in, STDIN_FILENO) == -1)
	{
		ft_err_hdl(1, d);
	}
	if (dup2(out, STDOUT_FILENO) == -1)
	{
		ft_err_hdl(1, d);
	}
}

/**
 * @brief Closes the file descriptors.
 *
 * @param d The process data.
 */
void	ft_close_fd(t_ProcessData *d)
{
	if (d->fdi != -1)
		close(d->fdi);
	if (d->fdo != -1)
		close(d->fdo);
	ft_close_pfd(d);
}
