/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:35:20 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/22 13:11:37 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_word_count(char const *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (!ft_isspace(s[i]) || (ft_isspace(s[i])
				&& ft_isinquote(s, i, false)))
		{
			count++;
			while ((!ft_isspace(s[i]) || (ft_isspace(s[i])
						&& ft_isinquote(s, i, false))) && s[i])
				i++;
		}
		if (ft_isspace(s[i]) && !ft_isinquote(s, i, false))
			i++;
	}
	return (count);
}
