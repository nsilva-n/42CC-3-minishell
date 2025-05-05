/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:22:26 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/05/05 11:50:02 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	ft_main_exec(t_pipex *pipes)
{
	if (!ft_rep_in_redir(pipes))
		return (false);
	if (!ft_rep_out_redir(pipes))
		return (false);
	if (ft_isbadcommand(pipes))
		return (glob()->exit_status = 1, false);
	if (!pipes->next)
		ft_exec_single_cmd(pipes);
	else
	{
		while (pipes)
		{
			if (!ft_new_child(pipes))
				return (false);
			pipes = pipes->next;
		}
		pipes = glob()->pipes;
		while (pipes)
		{
			ft_waitpid(pipes->pid);
			pipes = pipes->next;
		}
	}
	return (close_fds(), ft_main_signals(), true);
}
