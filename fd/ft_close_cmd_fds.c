/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_cmd_fds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:02:53 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/14 16:03:26 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_close_cmd_fds(t_pipex *pipes)
{
	if (!pipes)
		return ;
	if (pipes->has_doc)
		close(pipes->doc_pipe[0]);
	if (pipes->previous)
		close(pipes->previous->pipe[0]);
	if (pipes->next)
		close(pipes->pipe[1]);
	if (pipes->next)
		close(pipes->pipe[0]);
	exit(EXIT_FAILURE);
}
