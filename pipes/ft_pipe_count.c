/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:52:49 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/14 13:53:40 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_pipe_count(t_token *token)
{
	int	n_pipes;

	n_pipes = 0;
	while (token)
	{
		if (token->type == PIPE)
			n_pipes++;
		token = token->next;
	}
	return (n_pipes);
}
