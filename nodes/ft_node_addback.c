/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_addback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:45:15 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/21 17:57:37 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_node_addback(t_env *node, t_env *add, bool flag)
{
	t_env	*temp;
	t_env	*end;

	temp = node;
	if (!add->exported && ft_isnode(node, add))
		return ;
	while (temp)
	{
		if (!ft_strcmp(temp->key, add->key))
		{
			free(temp->value);
			free(temp->var);
			temp->var = ft_strdup(add->var);
			temp->value = ft_strdup(add->value);
			ft_free_node(add);
			return ;
		}
		end = temp;
		temp = temp->next;
	}
	if (!end)
		return ;
	end->next = add;
	add->exported = flag;
	add->prev = end;
}
