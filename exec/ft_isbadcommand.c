/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isbadcommand.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:30:47 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/05/05 11:31:05 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	ft_isbadcommand(t_pipex *pipes)
{
	t_pipex	*temp;

	temp = pipes;
	while (temp)
	{
		if (temp->bad_command)
			return (true);
		temp = temp->next;
	}
	return (false);
}
