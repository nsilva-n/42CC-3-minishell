/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_pipe_quotes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:08:46 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/16 13:14:31 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_remove_pipe_quotes(t_pipex *pipes)
{
	int	i;

	i = -1;
	while (pipes)
	{
		while (pipes->cmd && pipes->cmd[++i])
			pipes->cmd[i] = ft_remove_quotes(pipes->cmd[i]);
		i = -1;
		while (pipes->red_in && pipes->red_in[++i])
			pipes->red_in[i] = ft_remove_quotes(pipes->red_in[i]);
		i = -1;
		while (pipes->red_out && pipes->red_out[++i])
			pipes->red_out[i] = ft_remove_quotes(pipes->red_out[i]);
		pipes = pipes->next;
	}
}
