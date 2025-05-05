/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:16:43 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/17 16:15:02 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_expand_node(t_token *token, char *var)
{
	char	*new;
	t_index	index;

	ft_init_index(&index);
	new = malloc(ft_expanded_len(token, var) + 1);
	while (token->str[index.t_i] != '$')
		new[index.new_i++] = token->str[index.t_i++];
	while (var[index.var_i])
		new[index.new_i++] = var[index.var_i++];
	if (token->str[index.t_i + 1] == '?' || token->str[index.t_i + 1] == '$')
		index.t_i += 2;
	else
		index.t_i += ft_node_key_len(token->str, index.t_i + 1) + 1;
	while (token->str[index.t_i])
		new[index.new_i++] = token->str[index.t_i++];
	new[index.new_i] = '\0';
	free(token->str);
	token->str = new;
}
