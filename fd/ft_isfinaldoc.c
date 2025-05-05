/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfinaldoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:13:18 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/05/01 12:48:19 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	ft_isfinaldoc(t_pipex *pipes)
{
	int	i;

	i = -1;
	if (!pipes->red_in)
		return (false);
	while (pipes->red_in[++i])
	{
		if (!ft_strncmp(pipes->red_in[i], "APP:", 4))
			pipes->has_doc++;
	}
	return (true);
}
