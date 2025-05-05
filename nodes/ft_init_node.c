/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:46:09 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/22 13:51:07 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*ft_init_node(char *str)
{
	t_env	*new_node;
	int		i;

	new_node = (t_env *)malloc(sizeof(t_env));
	if (!new_node)
		return (NULL);
	new_node->var = ft_strdup(str);
	i = 0;
	while (str[i] != '=' && str[i])
		i++;
	new_node->key = ft_substr(str, 0, i);
	if (str[i] == '=')
	{
		new_node->value = ft_substr(str, i + 1, ft_strlen(str));
		new_node->exported = true;
	}
	else
	{
		new_node->value = ft_strdup("");
		new_node->exported = false;
	}
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}
