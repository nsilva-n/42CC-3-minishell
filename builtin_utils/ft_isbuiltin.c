/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isbuiltin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:44:14 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/17 16:58:43 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	ft_isbuiltin(t_pipex *pipes)
{
	if (!pipes || !pipes->cmd)
		return (false);
	return (!ft_strncmp(pipes->cmd[0], "exit", 5)
		|| !ft_strncmp(pipes->cmd[0], "echo", 5)
		|| !ft_strncmp(pipes->cmd[0], "pwd", 4)
		|| !ft_strncmp(pipes->cmd[0], "cd", 3)
		|| !ft_strncmp(pipes->cmd[0], "export", 7)
		|| !ft_strncmp(pipes->cmd[0], "unset", 6)
		|| !ft_strncmp(pipes->cmd[0], "env", 4)
		|| ft_strchr(pipes->cmd[0], '='));
}
