/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rep_in_redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:07:51 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/29 13:58:23 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	ft_rep_in_redir(t_pipex *pipes)
{
	t_pipex	*temp;

	temp = pipes;
	while (temp)
	{
		ft_isfinaldoc(temp);
		if (!ft_isloopdoc(temp))
			return (false);
		temp = temp->next;
	}
	temp = pipes;
	while (temp)
	{
		if (ft_open_in_files_loop(temp))
			return (false);
		temp = temp->next;
	}
	return (true);
}
