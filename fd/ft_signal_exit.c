/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:15:29 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/05/01 14:07:08 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_signal_exit(char *help, char *eof, t_pipex *pipes)
{
	if (help)
		free(help);
	ft_close(pipes->doc_pipe[1]);
	ft_fprintf(2, "minishell: warning: here-document at line x delimited ");
	ft_fprintf(2, "by end-of-file (wanted '%s')\n", eof);
	ft_exit(144);
}
