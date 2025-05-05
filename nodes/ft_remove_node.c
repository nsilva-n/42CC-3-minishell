/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:27:26 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/14 14:55:44 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_remove_node(char *str)
{
	t_env	*step;

	if (!str || !glob()->env)
		return ;
	step = glob()->env;
	while (step)
	{
		if (!ft_strcmp(step->key, str))
		{
			if (step->prev)
				step->prev->next = step->next;
			if (step->next)
				step->next->prev = step->prev;
			ft_free_node(step);
			break ;
		}
		step = step->next;
	}
}
