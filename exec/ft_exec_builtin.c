/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:23:39 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/05/01 14:43:17 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	close_fds(void)
{
	int	i;

	i = 2;
	while (++i <= 16)
		ft_close(i);
}

void	ft_exec_builtin(t_pipex *pipes)
{
	char	*cmd;

	cmd = pipes->cmd[0];
	if (!ft_strncmp(cmd, "cd", 3))
		ft_cd(pipes->cmd, pipes->out_fd);
	else if (!ft_strncmp(cmd, "pwd", 4))
		ft_pwd(pipes->out_fd);
	else if (!ft_strncmp(cmd, "env", 4))
		ft_env(glob()->env, pipes->cmd, pipes->out_fd);
	else if (!ft_strncmp(cmd, "echo", 5))
		ft_echo(pipes->cmd, pipes->out_fd);
	else if (!ft_strncmp(cmd, "unset", 6))
		ft_unset(pipes->cmd, glob()->env);
	else if (!ft_strncmp(cmd, "export", 7))
		ft_export(pipes->cmd, pipes->out_fd, true);
	else if (!ft_strncmp(cmd, "exit", 5))
		ft_exit_builtin(pipes->cmd);
	else if (ft_strchr(cmd, '='))
		ft_export(pipes->cmd, pipes->out_fd, false);
	if (pipes->red_out)
		ft_close(pipes->out_fd);
	if (!pipes->pid)
		ft_exit(glob()->exit_status);
}
