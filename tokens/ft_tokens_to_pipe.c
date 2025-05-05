/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokens_to_pipe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:01:33 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/14 17:07:00 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_tokens_to_pipe(t_token *token)
{
	t_pipex	*pipes;

	pipes = ft_get_pipe_list(token);
	ft_fill_pipes(token, pipes);
	glob()->pipes = pipes;
}
