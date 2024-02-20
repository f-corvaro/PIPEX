/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:41:57 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/02/16 19:36:30 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_b.h"

/**
 * @brief Handles quoted substrings in a string.
 *
 * @param str The string to process.
 * @param i The current index in the string.
 * @return A new string containing the quoted substring.
 */
char	*handle_quotes(char *str, int *i)
{
	char	quote_char;
	char	*start;

	quote_char = str[*i];
	(*i)++;
	start = &str[*i];
	while (str[*i] != quote_char)
		(*i)++;
	str[*i] = '\0';
	(*i)++;
	return (ft_strdup(start));
}

/**
 * @brief Handles non-quoted substrings in a string.
 *
 * @param str The string to process.
 * @param i The current index in the string.
 * @return A new string containing the non-quoted substring.
 */
char	*handle_no_quotes(char *str, int *i)
{
	char	*start;

	start = &str[*i];
	while (str[*i] != ' ' && str[*i] != '\0')
		(*i)++;
	if (str[*i] == ' ')
	{
		str[*i] = '\0';
		(*i)++;
	}
	return (ft_strdup(start));
}

/**
 * @brief Splits a string into substrings based on quotes and spaces.
 *
 * @param str The string to split.
 * @return An array of strings, each containing a substring.
 */
char	**ft_split_quotes(char *str)
{
	char	**result;
	int		i;
	int		j;

	result = malloc(MAX_ARGS * sizeof(char *));
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '"' || str[i] == '\'')
			result[j] = handle_quotes(str, &i);
		else
			result[j] = handle_no_quotes(str, &i);
		j++;
	}
	result[j] = NULL;
	return (result);
}
