/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_global.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:56:42 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/05/01 14:04:53 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_init_global(char **envp)
{
	t_global	*global;

	global = glob();
	global->token = NULL;
	global->env = ft_get_env(envp);
	global->input = NULL;
	global->pwd = NULL;
	global->pwd = getcwd(NULL, 0);
	global->home = ft_get_home();
	global->exit_status = 0;
	global->line_nbr = 0;
	global->signaled = false;
	global->heredoc_str = NULL;
}
