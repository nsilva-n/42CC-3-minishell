/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_wout_quote.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:55:19 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/14 16:33:10 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_copy_woutquote(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_issquote(src[i]))
	{
		i++;
		while (!ft_issquote(src[i]) && src[i])
			dest[j++] = src[i++];
	}
	else if (ft_isdquote(src[i]))
	{
		i++;
		while (!ft_isdquote(src[i]) && src[i])
			dest[j++] = src[i++];
	}
}
