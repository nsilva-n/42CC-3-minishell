/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expanded_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:02:39 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/16 15:34:09 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_expanded_len(t_token *t, char *var_value)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (t->str[i] != '$')
		i++;
	len += i;
	i += ft_node_key_len(t->str, i) - 1;
	while (t->str[++i])
		len++;
	return (len + ft_strlen(var_value));
}
