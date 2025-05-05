/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:45:14 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/30 20:08:40 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	ft_new_child(t_pipex *pipes)
{
	if (!pipes)
		return (false);
	if (pipe(pipes->pipe) < 0)
		return (ft_error("pipe", 1));
	signal(SIGINT, SIG_IGN);
	pipes->pid = fork();
	if (!pipes->bad_command && pipes->pid < 0)
		return (ft_error("fork", 1));
	if (!pipes->pid)
	{
		ft_default_signals();
		ft_child_process(pipes);
	}
	if (pipes->previous)
		ft_close(pipes->previous->pipe[0]);
	if (pipes->has_doc)
		ft_close(pipes->doc_pipe[0]);
	ft_close(pipes->pipe[1]);
	if (!pipes->next)
		ft_close(pipes->pipe[0]);
	if (pipes->red_out)
		ft_close(pipes->out_fd);
	return (true);
}
