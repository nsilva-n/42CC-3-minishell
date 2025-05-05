/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_pipe_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:36:36 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/14 13:54:59 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_free_pipe_list(t_pipex *pipes)
{
	t_pipex	*temp;

	while (pipes)
	{
		temp = pipes->next;
		if (pipes->cmd)
			ft_free_strs(pipes->cmd);
		if (pipes->red_in)
			ft_free_strs(pipes->red_in);
		if (pipes->red_out)
			ft_free_strs(pipes->red_out);
		free(pipes);
		pipes = temp;
	}
}
