/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:13:03 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/22 13:51:04 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_free_node(t_env *node)
{
	if (!node)
		return ;
	if (node->var)
		free(node->var);
	if (node->key)
		free(node->key);
	if (node->value)
		free(node->value);
	free(node);
}
