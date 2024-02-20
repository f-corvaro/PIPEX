/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_b.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:24:49 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/02/20 19:55:52 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ------------  HEADER GUARD  ---------------------------------------------- */
#ifndef PIPEX_B_H
# define PIPEX_B_H

/*
 * Different operating systems have different default file permissions when a
 new file is created. On macOS, the default file permissions are 0644
 (-rw-r--r--), while on many Linux systems, the default file permissions are
 0664 (-rw-rw-r--).
 *
 * To handle this difference, I use preprocessor directives to check the
 * operating system at compile time and define the appropriate file permissions.
 */
/* ------------  APPLE SPECIFIC DEFINITIONS  -------------------------------- */
# ifdef __APPLE__
#  define FILE_PERMISSIONS 0644

/* ------------  NON-APPLE SPECIFIC DEFINITIONS  ---------------------------- */
# else
#  define FILE_PERMISSIONS 0664
# endif

/* ------------  MAXIMUM ARGUMENTS DEFINITION  ------------------------------ */
# define MAX_ARGS 100

/* ------------  My LIBRARY  ------------------------------------------------ */
# include "ft_printf.h"

/* ------------  String Manipulation Functions  ----------------------------- */
# include <string.h>

/* ------------  Standard Integer Types  ------------------------------------ */
# include <stdint.h>

/* ------------  Process State Change Waiting Functions  -------------------- */
# include <sys/wait.h>

/* ------------  Error Number Definitions and Error Reporting  -------------- */
# include <errno.h>

/**
 * @struct t_ProcessData
 * @brief A structure to hold process data for pipex.
 *
 * @param ac Argument count.
 * @param av Argument vector.
 * @param fdi File descriptor for input.
 * @param fdo File descriptor for output.
 * @param env_vrb Environment variables.
 * @param heredoc Flag for heredoc mode, set to 1 if heredoc mode is used,
 * 0 otherwise.
 * @param pipe Pipe file descriptors.
 * processes.
 * @param child_f Flag for child process.
 * @param pids Process IDs.
 * @param cmd_path Path to the command to be executed.
 * @param cmd_opts Command options.
 * @param cmd_count Command count.
 */
typedef struct s_ProcessData
{
	int		ac;
	char	**av;
	int		fdi;
	int		fdo;
	char	**env_vrb;
	int		heredoc;
	int		*pipe;
	int		child_f;
	int		*pids;
	char	*cmd_path;
	char	**cmd_opts;
	int		cmd_count;
}		t_ProcessData;

/* -> ft_environment_op.c --------------------------------------------------- */

char			*ft_cmd_path(char *cmd, t_ProcessData *d);

/* -> ft_error_handling.c --------------------------------------------------- */

void			ft_err_hdl(int es, t_ProcessData *d);
int				ft_disp_err(char *e1, char *e2, char *e3, int es);

/* -> ft_file_in_out_op.c --------------------------------------------------- */

void			ft_hdoc_hdl(t_ProcessData *d);
void			ft_open_in(t_ProcessData *d);
void			ft_open_out(t_ProcessData *d);
void			ft_redir_io(int in, int out, t_ProcessData *d);
void			ft_close_fd(t_ProcessData *d);

/* -> ft_init.c ------------------------------------------------------------- */

t_ProcessData	ft_set_pd(int ac, char **av, char **ev);

/* -> ft_memory_management.c ------------------------------------------------ */

void			ft_free_s_a(char *ss, char **sa);

/* -> ft_no_environment_op.c ------------------------------------------------ */

char			*ft_find_exe_hardcoded(char *cmd);

/* -> ft_pipe.c ------------------------------------------------------------- */

void			ft_mk_pipes(t_ProcessData *d);
void			ft_close_pfd(t_ProcessData *d);
int				ft_run_pipe(t_ProcessData *d);

/* -> ft_process_management.c ----------------------------------------------- */

void			ft_hdl_chldp(t_ProcessData *d);
int				ft_hdl_prntp(t_ProcessData *d);

/* -> ft_utils.c ------------------------------------------------------------ */

char			*handle_quotes(char *str, int *i);
char			*handle_no_quotes(char *str, int *i);
char			**ft_split_quotes(char *str);

#endif