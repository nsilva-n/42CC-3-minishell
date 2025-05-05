/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:26:38 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/25 13:32:46 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_token_split(char const *str)
{
	char	**res;
	int		word_count;
	int		i;

	if (!str)
		return (NULL);
	word_count = ft_word_count(str);
	if (!word_count)
		return (NULL);
	res = malloc(sizeof(char *) * (word_count + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < word_count)
	{
		while (ft_isspace(*str))
			str++;
		res[i] = ft_substr((char *)str, 0, ft_word_len((char *)str));
		if (!res[i])
			return (NULL);
		str += ft_word_len((char *)str);
	}
	return (res[i] = NULL, res);
}
