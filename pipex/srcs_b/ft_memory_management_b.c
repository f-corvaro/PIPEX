/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory_management_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:31:49 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/02/16 19:35:02 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_b.h"

/**
 * @brief Frees a string and a string array.
 *
 * @param ss The string to be freed.
 * @param sa The string array to be freed.
 */
void	ft_free_s_a(char *ss, char **sa)
{
	int	i;

	if (ss != NULL)
	{
		free(ss);
		ss = NULL;
	}
	if (sa != NULL)
	{
		i = 0;
		while (sa[i])
		{
			free(sa[i]);
			i++;
		}
		free(sa);
		sa = NULL;
	}
}
