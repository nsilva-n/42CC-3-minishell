/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalidfirstparse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:41:31 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/16 16:02:10 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	ft_isvalidfirstparse(t_token *token)
{
	t_token	*temp;

	temp = token;
	while (temp)
	{
		if (temp->type == PIPE && !ft_isvalidpipe(temp))
			return (ft_fprintf(2, "unexpected error near \"|\"\n"), false);
		else if (temp->type == RED_APP || temp->type == RED_IN
			|| temp->type == RED_OUT || temp->type == HERE_DOC)
		{
			if (!ft_isvalidredir(temp))
				return (ft_error_redir(temp));
		}
		temp = temp->next;
	}
	return (true);
}
