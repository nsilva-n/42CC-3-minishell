/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_in_files_loop.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:14:24 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/22 13:53:24 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	ft_open_in_files_loop(t_pipex *pipes)
{
	int	i;

	i = -1;
	if (!pipes->red_in)
		return (false);
	while (pipes->red_in[++i])
		if (!ft_strncmp(pipes->red_in[i], "STD:", 4) && !pipes->bad_command
			&& !ft_open_input_file(pipes->red_in[i] + 4, pipes))
			break ;
	if (pipes->has_doc)
		ft_close(pipes->in_fd);
	return (true);
}
