/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:41:13 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/29 14:45:46 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_input_redir(t_pipex *pipes)
{
	if (!pipes)
		return ;
	if (pipes->previous)
	{
		if (!pipes->red_in)
			dup2(pipes->previous->pipe[0], STDIN_FILENO);
		close(pipes->previous->pipe[0]);
	}
	if (pipes->red_in)
	{
		if (pipes->has_doc)
		{
			if (pipes->doc_pipe[0])
				dup2(pipes->doc_pipe[0], STDIN_FILENO);
			ft_close(pipes->doc_pipe[0]);
		}
		else
		{
			if (pipes->in_fd)
				dup2(pipes->in_fd, STDIN_FILENO);
			ft_close(pipes->in_fd);
		}
	}
}
