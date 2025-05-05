/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mini_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:46:19 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/17 17:19:03 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*ft_init_mini_env(void)
{
	t_env	*env;
	char	cwd[4096];

	if (!getcwd(cwd, sizeof(cwd)))
		ft_error("getcwd", 1);
	env = ft_init_node("PWD=");
	free(env->value);
	env->value = ft_strdup(cwd);
	ft_node_addback(env, ft_init_node("LS_COLORS="), true);
	ft_node_addback(env, ft_init_node("SHLVL=1"), true);
	ft_node_addback(env, ft_init_node("PATH=/usr/local/bin:"
			"/usr/local/sbin:/usr/bin:/usr/sbin:/bin:/sbin"), true);
	ft_node_addback(env, ft_init_node("_=/usr/bin/env"), true);
	return (env);
}
