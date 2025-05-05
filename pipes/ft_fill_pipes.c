/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_pipes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:05:12 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/16 13:48:02 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_fill_pipes(t_token *token, t_pipex *start)
{
	t_pipex	*temp;
	t_token	*t;

	t = token;
	temp = start;
	while (t)
	{
		if (t->type == HERE_DOC)
			temp->red_in = ft_add_handler(temp->red_in, t->next->str, "APP:");
		else if (t->type == RED_IN)
			temp->red_in = ft_add_handler(temp->red_in, t->next->str, "STD:");
		else if (t->type == RED_OUT)
			temp->red_out = ft_add_handler(temp->red_out, t->next->str, "STD:");
		else if (t->type == RED_APP)
			temp->red_out = ft_add_handler(temp->red_out, t->next->str, "APP:");
		else if (t->type == WORD)
			temp->cmd = ft_add_handler(temp->cmd, t->str, NULL);
		else if (t->type == PIPE)
			temp = temp->next;
		if (t->type == WORD || t->type == PIPE)
			t = t->next;
		else
			t = t->next->next;
	}
}
