/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:49:41 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/17 17:18:43 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*ft_get_env(char **envp)
{
	t_env	*new;
	t_env	*start;
	int		i;

	if (!ft_strs_count(envp))
		return (ft_init_mini_env());
	start = ft_init_node(envp[0]);
	i = 0;
	while (envp[++i])
	{
		new = ft_init_node(envp[i]);
		ft_node_addback(start, new, true);
	}
	return (start);
}
