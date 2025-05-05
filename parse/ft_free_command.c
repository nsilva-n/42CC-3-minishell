/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:39:52 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/29 14:45:56 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_free_command(void)
{
	if (!glob())
		return ;
	if (glob()->input)
		free(glob()->input);
	if (glob()->token)
	{
		ft_free_token_list(glob()->token);
		glob()->token = NULL;
	}
	if (glob()->pipes)
	{
		if (glob()->pipes->has_doc)
			ft_close_fds(glob()->pipes->doc_pipe);
		ft_close(glob()->pipes->in_fd);
		ft_close(glob()->pipes->out_fd);
		ft_free_pipe_list(glob()->pipes);
		glob()->pipes = NULL;
	}
	glob()->signaled = false;
}
