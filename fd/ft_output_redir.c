/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:42:11 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/30 20:14:13 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_output_redir(t_pipex *pipes)
{
	if (!pipes)
		return ;
	if (pipes->next)
	{
		if (!pipes->red_out)
			dup2(pipes->pipe[1], STDOUT_FILENO);
		ft_close(pipes->pipe[1]);
	}
	if (!pipes->red_out)
		return ;
	dup2(pipes->out_fd, STDOUT_FILENO);
}
