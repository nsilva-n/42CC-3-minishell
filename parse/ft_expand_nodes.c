/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_nodes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:27:32 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/22 09:53:48 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_expand_nodes(t_token *start, int flag)
{
	t_token	*tmp;

	tmp = start;
	while (tmp)
	{
		if (flag)
			ft_hide_expand(tmp->str);
		if (ft_isexpandneeded(tmp))
			ft_expand(tmp);
		else
		{
			ft_unhide_expand(tmp->str);
			tmp = tmp->next;
		}
	}
}
