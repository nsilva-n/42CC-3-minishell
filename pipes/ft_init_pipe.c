/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:49:35 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/22 13:51:18 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_pipex	*ft_init_pipe(void)
{
	t_pipex	*new_pipe;

	new_pipe = (t_pipex *)malloc(sizeof(t_pipex));
	if (!new_pipe)
		return (NULL);
	new_pipe->next = NULL;
	new_pipe->previous = NULL;
	new_pipe->red_in = NULL;
	new_pipe->red_out = NULL;
	new_pipe->cmd = NULL;
	new_pipe->in_fd = 0;
	new_pipe->out_fd = 1;
	new_pipe->pid = -1;
	new_pipe->has_doc = 0;
	new_pipe->bad_command = false;
	new_pipe->path = NULL;
	new_pipe->doc_pipe[0] = 0;
	new_pipe->doc_pipe[1] = 0;
	new_pipe->pipe[0] = 0;
	new_pipe->pipe[1] = 0;
	return (new_pipe);
}
