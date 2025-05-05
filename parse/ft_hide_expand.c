/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hide_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:59:03 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/16 15:56:19 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_hide_expand(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '$' && ft_isinquote(str, i, false) && str[i + 1] == '\"')
			str[i] = -1;
		if (str[i] == '$' && ft_isinquote(str, i, true))
			str[i] = -1;
		if (str[i] == '$' && str[i + 1] == '\''
			&& ft_isinquote(str, i + 1, false))
			str[i] = -1;
		if (str[i] == '$' && str[i + 1] == '\0' && i != 0 && str[i - 1] != '$')
			str[i] = -1;
	}
}
