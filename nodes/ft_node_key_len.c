/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_key_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:19:15 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/16 15:40:05 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_node_key_len(char *key, int i)
{
	int	len;

	len = 0;
	if (ft_isspecialexpand(key + i))
		return (ft_isspecialexpand(key + i));
	if (ft_isdigit(key[i]))
		return (1);
	if (!ft_isalpha(key[i]) && key[i] != '_')
		return (0);
	while (key[i + len] != -1
		&& (ft_isdigit(key[i + len])
			|| ft_isalpha(key[i + len]) || key[i + len] == '_')
		&& key[i + len] && key[i + len] != '$' && !ft_isquote(key[i + len]))
		len++;
	return (len);
}
