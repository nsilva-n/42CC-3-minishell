/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_single_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:19:19 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/29 13:55:07 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	ft_exec_single_cmd(t_pipex *pipes)
{
	if (pipes->bad_command)
		return (false);
	if (ft_isbuiltin(pipes))
		ft_exec_builtin(pipes);
	else
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		pipes->pid = fork();
		if (pipes->pid == -1)
			return (ft_error("fork", 1), false);
		if (!pipes->pid)
		{
			ft_default_signals();
			ft_child_process(pipes);
			ft_exit(127);
		}
		ft_waitpid(pipes->pid);
	}
	return (true);
}
