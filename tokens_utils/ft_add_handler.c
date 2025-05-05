/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:41:41 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/16 12:52:50 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_add_handler(char **words, char *word, char *prefix)
{
	char	*new_add;

	if (prefix)
		new_add = ft_strjoin(prefix, word);
	else
		new_add = ft_strdup(word);
	return (ft_add_to_strs(words, new_add));
}
