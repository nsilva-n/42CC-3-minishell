/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_addback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:50:37 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/14 13:51:53 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_pipe_addback(t_pipex *pipes, t_pipex *add)
{
	t_pipex	*temp;

	if (!pipes || !add)
		return ;
	temp = pipes;
	while (temp->next)
		temp = temp->next;
	temp->next = add;
	add->previous = temp;
}
