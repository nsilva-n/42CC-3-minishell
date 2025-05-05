/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_nobar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 09:36:39 by mlameira          #+#    #+#             */
/*   Updated: 2025/04/21 10:23:41 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../minishell.h"

size_t	ft_strlcpy_nobar(char *dst, const char *src, size_t size)
{
	size_t	len_src;
	int		i;
	int		j;

	len_src = ft_strlen(src);
	if (dst == NULL || src == NULL)
		return (0);
	i = 0;
	j = 0;
	if (size > 0)
	{
		while (src[i] && (size_t)i < (size - 1))
		{
			if (ft_isinquote(src, i, false))
				dst[j++] = src[i++];
			else if (src[i] != '\\' || (src[i] == '\\' && src[i + 1] == '\\'))
				dst[j++] = src[i++];
			else
				i++;
		}
		dst[i] = '\0';
	}
	return (len_src);
}
