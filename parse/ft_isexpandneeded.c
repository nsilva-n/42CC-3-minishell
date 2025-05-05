/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isexpandneeded.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:29:05 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/22 09:55:51 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	ft_isexpandneeded(t_token *token)
{
	int	i;

	i = -1;
	if (!token || !token->str)
		return (false);
	if (ft_strlen(token->str) == 1 && token->str[0] == '$')
		return (false);
	while (token->str[++i])
	{
		if (token->prev && token->prev->type == HERE_DOC)
			return (false);
		if (token->str[i] == '$')
			return (true);
	}
	return (false);
}
