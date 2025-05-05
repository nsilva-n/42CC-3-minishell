/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:31:12 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/17 16:29:29 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_expand(t_token *token)
{
	char	*key;
	char	*value;

	key = ft_get_node_key(token);
	if (ft_isspecialexpand(key))
		value = ft_get_special_node(key);
	else
		value = ft_get_node_value(glob()->env, key);
	ft_expand_node(token, value);
	free(key);
	free(value);
}
