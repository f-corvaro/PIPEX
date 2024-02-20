/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_environment_op.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:06:38 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/02/18 11:51:24 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief Creates a path and checks if it's accessible.
 *
 * @param path The base path.
 * @param cmd The command to append to the path.
 * @return The accessible path, or NULL if not accessible.
 */
static char	*create_and_check_path(char *path, char *cmd)
{
	char	*ep;

	ep = ft_strjoin(path, cmd);
	if (!ep)
		ft_err_hdl(ft_disp_err("unexpected error", "", "", 1), NULL);
	if (access(ep, F_OK | X_OK) == 0)
		return (ep);
	ft_free_s_a(ep, NULL);
	return (NULL);
}

/**
 * @brief Finds an executable in hardcoded paths.
 *
 * @param cmd The command to find.
 * @return The path to the executable, or NULL if not found.
 */
char	*ft_find_exe_hardcoded(char *cmd)
{
	int		i;
	char	*ep;
	char	*hardcoded_paths[7];

	hardcoded_paths[0] = "/usr/local/sbin/";
	hardcoded_paths[1] = "/usr/local/bin/";
	hardcoded_paths[2] = "/usr/sbin/";
	hardcoded_paths[3] = "/usr/bin/";
	hardcoded_paths[4] = "/sbin/";
	hardcoded_paths[5] = "/bin/";
	hardcoded_paths[6] = NULL;
	i = 0;
	while (hardcoded_paths[i])
	{
		ep = create_and_check_path(hardcoded_paths[i], cmd);
		if (ep)
			return (ep);
		i++;
	}
	return (NULL);
}
