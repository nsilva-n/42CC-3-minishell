/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_expand.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:20:57 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/29 13:39:17 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_heredoc_expand(char *str)
{
	t_token	*temp;
	char	*res;

	if (!str || !*str)
		return (NULL);
	temp = ft_init_token(str);
	ft_expand_nodes(temp, false);
	res = ft_strdup(temp->str);
	return (ft_free_token(temp), free(str), res);
}
