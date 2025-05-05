/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isloopdoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:12:32 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/16 15:00:33 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	ft_isloopdoc(t_pipex *pipes)
{
	int	i;

	i = -1;
	while (++i >= 0 && pipes->red_in && pipes->red_in[i] && !pipes->bad_command)
		if (!ft_strncmp(pipes->red_in[i], "APP:", 4)
			&& !ft_open_doc(pipes->red_in[i] + 4, pipes))
			return (ft_close(pipes->doc_pipe[0]), false);
	if (!pipes->has_doc)
		ft_close(pipes->doc_pipe[0]);
	return (true);
}
