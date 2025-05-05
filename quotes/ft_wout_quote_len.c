/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wout_quote_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:07:26 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/16 13:16:22 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

size_t	ft_wout_quote_len(char *str)
{
	size_t	len;
	int		i;

	len = ft_strlen(str);
	i = -1;
	if (!len)
		return (0);
	while (str[++i])
	{
		if (ft_isquote(str[i]))
		{
			len -= 2;
			i += ft_quoted_len(str, i) - 1;
		}
	}
	return (len);
}
