/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_split_to_token.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:34:21 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/16 16:09:03 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*ft_input_split_to_token(char **words)
{
	t_token	*res;
	t_token	*temp;
	int		i;
	int		word_count;

	word_count = 0;
	if (!words)
		return (NULL);
	while (words[word_count])
		word_count++;
	if (!word_count)
		return (NULL);
	res = ft_init_token(words[0]);
	i = 0;
	while (words[++i])
	{
		temp = ft_init_token(words[i]);
		ft_token_addback(res, temp);
	}
	return (ft_free_strs(words), res);
}
