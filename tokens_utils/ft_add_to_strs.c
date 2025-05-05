/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_strs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:38:21 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/17 15:45:08 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_add_to_strs(char **words, char *word)
{
	int		word_count;
	char	**res;
	int		i;

	i = -1;
	word_count = 0;
	if (!word)
		return (words);
	if (!words)
	{
		res = malloc(sizeof(char *) * 3);
		if (!res)
			return (NULL);
		return (res[++i] = word, res[++i] = NULL, res[++i] = NULL,
			ft_free_strs(words), res);
	}
	while (words[word_count])
		word_count++;
	res = malloc(sizeof(char *) * (word_count + 2));
	if (!res)
		return (NULL);
	while (++i < word_count)
		res[i] = ft_strdup(words[i]);
	return (res[i] = word, res[++i] = NULL, ft_free_strs(words), res);
}
