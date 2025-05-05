/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:10:52 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/16 13:16:22 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_remove_quotes(char *str)
{
	char	*ret;
	int		i;
	int		ret_i;

	i = -1;
	ret_i = 0;
	if (ft_strlen(str) == ft_wout_quote_len(str))
		return (str);
	ret = malloc(ft_wout_quote_len(str) + 2);
	if (ft_wout_quote_len(str))
	{
		while (str[++i])
		{
			if (ft_isquote(str[i]))
			{
				ft_copy_woutquote(ret + ret_i, str + i);
				ret_i += ft_quoted_len(str, i) - 2;
				i += ft_quoted_len(str, i) - 1;
			}
			else
				ret[ret_i++] = str[i];
		}
	}
	return (ret[ret_i] = '\0', free(str), ret);
}
