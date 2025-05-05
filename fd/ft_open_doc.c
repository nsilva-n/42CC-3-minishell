/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:34:15 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/05/01 14:08:58 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	ft_open_doc(char *str, t_pipex *pipes)
{
	int	pid;

	ft_close(pipes->doc_pipe[0]);
	if (pipes->doc_pipe[0] < 0)
		return (ft_error("pipe", 1));
	pid = fork();
	if (pid < 0)
		return (ft_close_fds(pipes->doc_pipe), ft_error("fork", 1));
	if (!pid)
		ft_rl_to_doc(str, pipes);
	signal(SIGINT, SIG_IGN);
	ft_close(pipes->doc_pipe[1]);
	ft_waitpid(pid);
	if (glob()->exit_status == 130)
		return (false);
	if (glob()->exit_status == 144)
		return (glob()->exit_status = 0, true);
	return (true);
}
