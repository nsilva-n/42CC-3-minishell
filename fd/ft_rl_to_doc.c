/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl_to_doc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:35:47 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/05/05 11:42:26 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_rl_to_doc(char *eof, t_pipex *pipes)
{
	char	*help;

	signal(SIGINT, SIG_DFL);
	ft_close(pipes->doc_pipe[0]);
	ft_heredoc_signals();
	while (1)
	{
		help = readline("here_doc>");
		if (!help)
			ft_signal_exit(help, eof, pipes);
		if (!ft_strcmp(help, eof))
		{
			free(help);
			break ;
		}
		glob()->heredoc_str = ft_process_heredoc(help, glob()->heredoc_str);
	}
	if (pipes->cmd && !ft_strcmp(pipes->cmd[0], "cat")
		&& !ft_strcmp(eof, ft_last_heredoc(glob()->token)))
		ft_fprintf(pipes->doc_pipe[1], "%s", glob()->heredoc_str);
	ft_exit(0);
}
