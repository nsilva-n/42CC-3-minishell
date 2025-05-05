/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:40:56 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/05/01 14:05:23 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_free(void)
{
	t_global	*global;

	global = glob();
	if (!global)
		return ;
	if (global->pwd)
		free(global->pwd);
	if (global->home)
		free(global->home);
	if (global->input)
		free(global->input);
	if (global->token)
		ft_free_token_list(global->token);
	if (global->pipes)
		ft_free_pipe_list(global->pipes);
	if (global->env)
		ft_free_env(global->env);
	if (global->heredoc_str)
		free(global->heredoc_str);
	clear_history();
}
