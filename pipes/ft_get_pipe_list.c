/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pipe_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:32:08 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/14 14:33:35 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_pipex	*ft_get_pipe_list(t_token *token)
{
	int		n_pipes;
	t_pipex	*new;
	t_pipex	*temp;
	int		i;

	i = -1;
	n_pipes = ft_pipe_count(token);
	new = ft_init_pipe();
	while (++i < n_pipes)
	{
		temp = ft_init_pipe();
		ft_pipe_addback(new, temp);
	}
	return (new);
}
