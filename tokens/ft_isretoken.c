/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isretoken.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:55:20 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/16 15:55:07 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	ft_isretoken(char *str)
{
	int		i;
	bool	has_op;
	bool	has_words;

	i = -1;
	has_op = false;
	has_words = false;
	while (str[++i])
	{
		if (ft_isoperator(str, i) && !ft_isinquote(str, i, false))
			has_op = true;
		else
			has_words = true;
	}
	return ((has_op && has_words)
		|| (ft_operator_len(str, 0) < (int)ft_strlen(str) && has_op));
}
