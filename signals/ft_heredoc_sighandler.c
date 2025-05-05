/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_sighandler.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:36:39 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/05/05 11:36:52 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_heredoc_sighandler(int sig)
{
	(void)sig;
	printf("%s\n", __func__);
	ft_close(glob()->pipes->doc_pipe[1]);
	ft_default_signals();
	ft_exit(130);
}
