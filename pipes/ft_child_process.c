/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:39:36 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/05/05 11:39:40 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_child_process(t_pipex *pipes)
{
	char	*path;
	char	**envp;

	if (!pipes || pipes->bad_command)
		ft_close_cmd_fds(pipes);
	ft_input_redir(pipes);
	ft_output_redir(pipes);
	if (pipes->next || pipes->previous)
		ft_close_fds(pipes->pipe);
	if (!pipes->cmd)
		return (ft_close(pipes->out_fd), ft_exit(EXIT_SUCCESS));
	if (ft_isbuiltin(pipes))
		ft_exec_builtin(pipes);
	else
	{
		if (!ft_strcmp(pipes->cmd[0], "cat") && pipes->has_doc)
			ft_exit(0);
		envp = ft_env_to_strs(glob()->env);
		if (!ft_strchr(pipes->cmd[0], '/') && !ft_strchr(pipes->cmd[0], ' '))
			path = ft_get_path(pipes->cmd[0], envp);
		else
			path = pipes->cmd[0];
		ft_execute(path, pipes, envp);
	}
}
