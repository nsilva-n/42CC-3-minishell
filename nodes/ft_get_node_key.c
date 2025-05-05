/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_node_key.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:53:00 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/16 12:32:32 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_get_node_key(t_token *token)
{
	int	i;

	i = 0;
	while (token->str[i] != '$')
		i++;
	i++;
	if (token->str[i] == '$' || token->str[i] == '?')
		return (ft_substr(token->str, i, 1));
	return (ft_substr(token->str, i, ft_node_key_len(token->str, i)));
}
