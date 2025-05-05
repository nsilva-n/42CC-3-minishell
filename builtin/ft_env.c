/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:14:17 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/14 14:53:54 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	ft_env(t_env *env, char **args, int fd)
{
	if (!env)
		return (glob()->exit_status = 1, false);
	if (args[1])
		return (ft_error_env(args[1], 127, fd), false);
	while (env)
	{
		if (env->exported)
			ft_fprintf(fd, "%s=%s\n", env->key, env->value);
		env = env->next;
	}
	return (glob()->exit_status = 0, true);
}
