/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_environment_op.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:50:44 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/02/16 18:24:41 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief Extracts the PATH from the environment variables array.
 *
 * @param ev Null-terminated array of strings. Each string is 'key=value'.
 * @return The value of the PATH variable, or NULL if not found.
 *			The returned string should be freed when no longer needed.
 */
static char	*ft_extract_path(char **ev)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	while (ev[i] != NULL && ev[i][0] != '\0')
	{
		path = ft_strnstr(ev[i], "PATH=", 5);
		if (path)
		{
			path = ft_substr(path, 5, ft_strlen(path));
			break ;
		}
		i++;
	}
	return (path);
}

/**
 * @brief Adds a slash to the end of each path in the array.
 *
 * @param paths Null-terminated array of path strings.
 * @return The modified array of path strings.
 */
static char	**ft_add_slashes(char **paths)
{
	int		i;
	char	*tmp_path;

	i = 0;
	tmp_path = NULL;
	while (paths[i])
	{
		tmp_path = paths[i];
		paths[i] = ft_strjoin(paths[i], "/");
		ft_free_s_a(tmp_path, NULL);
		i++;
	}
	return (paths);
}

/**
 * @brief Formats the PATH environment variable.
 *
 * @param ev Null-terminated array of environment variables.
 * @return An array of paths from the PATH variable.
 */
static char	**ft_envpath_fmt(char **ev)
{
	char	*evp;
	char	**plps;

	evp = ft_extract_path(ev);
	if (!evp)
		return (NULL);
	plps = ft_split(evp, ':');
	ft_free_s_a(evp, NULL);
	if (!plps)
		return (NULL);
	plps = ft_add_slashes(plps);
	if (!plps)
		return (NULL);
	return (plps);
}

/**
 * @brief Finds the executable in the provided paths.
 *
 * @param cmd The command to find.
 * @param ps Null-terminated array of paths.
 * @return The path to the executable, or NULL if not found.
 * 			The caller is responsible for freeing the returned string.
 */
static char	*ft_find_exe(char *cmd, char **ps)
{
	int		i;
	char	*ep;

	ep = NULL;
	i = 0;
	while (ps[i])
	{
		ep = ft_strjoin(ps[i], cmd);
		if (!ep)
		{
			ft_free_s_a(NULL, ps);
			ft_err_hdl(ft_disp_err("unexpected error", "", "", 1), NULL);
		}
		if (access(ep, F_OK | X_OK) == 0)
			return (ep);
		ft_free_s_a(ep, NULL);
		i++;
	}
	return (NULL);
}

/**
 * @brief Finds the path of the command in the environment variables.
 *
 * @param cmd The command to find.
 * @param d The process data.
 * @return The path to the command, or NULL if not found.
 */
char	*ft_cmd_path(char *cmd, t_ProcessData *d)
{
	char	**evp;
	char	*exp;
	char	*tmp;

	if (access(cmd, F_OK | X_OK) == 0)
		return (ft_strdup(cmd));
	evp = ft_envpath_fmt(d->env_vrb);
	if (!evp)
	{
		exp = ft_find_exe_hardcoded(cmd);
		if (!exp)
		{
			tmp = d->av[d->child_f + 2];
			ft_disp_err(tmp, ": ", "command not found", 127);
		}
		return (exp);
	}
	exp = ft_find_exe(cmd, evp);
	if (!exp)
	{
		tmp = d->av[d->child_f + 2];
		ft_disp_err(tmp, ": ", "command not found", 127);
	}
	ft_free_s_a(NULL, evp);
	return (exp);
}
