/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinquote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:01:06 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/16 15:55:19 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	ft_isinquote(const char *input, int index, bool flag)
{
	int		i;
	bool	q_flag;
	bool	s_flag;

	i = -1;
	q_flag = false;
	s_flag = false;
	while (++i >= 0 && i < index && input[i])
	{
		if (ft_isdquote(input[i]) && !s_flag)
			q_flag = !q_flag;
		else if (ft_issquote(input[i]) && !q_flag)
			s_flag = !s_flag;
	}
	if (flag)
		return (!q_flag && s_flag);
	return (q_flag || s_flag);
}
