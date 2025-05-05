/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:49:28 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/14 14:50:42 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	ft_isnode(t_env *node, t_env *new)
{
	t_env	*temp;

	temp = node;
	while (temp)
	{
		if (!ft_strcmp(temp->key, new->key))
			return (true);
		temp = temp->next;
	}
	return (false);
}
