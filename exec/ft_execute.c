/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:39:48 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/05/05 11:39:58 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_execute(char *path, t_pipex *pipes, char **envp)
{
	if (execve(path, pipes->cmd, envp) == -1)
		return (ft_error_execve(pipes->cmd[0]),
			ft_free_strs(envp), ft_exit(127));
}
