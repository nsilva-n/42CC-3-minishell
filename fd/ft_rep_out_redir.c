/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rep_out_redir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:04:42 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/05/01 14:22:10 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	ft_rep_out_redir(t_pipex *pipes)
{
	int	i;

	while (pipes)
	{
		i = -1;
		if (!pipes->red_out)
		{
			pipes = pipes->next;
			continue ;
		}
		while (pipes->red_out[++i])
		{
			if (!ft_strncmp(pipes->red_out[i], "STD:", 4))
				ft_open_std_out(pipes->red_out[i] + 4, pipes);
			else if (!ft_strncmp(pipes->red_out[i], "APP:", 4))
				ft_open_app_out(pipes->red_out[i] + 4, pipes);
			if (pipes->bad_command)
				return (false);
		}
		pipes = pipes->next;
	}
	return (true);
}
