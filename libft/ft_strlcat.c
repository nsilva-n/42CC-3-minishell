/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:34:31 by mlameira          #+#    #+#             */
/*   Updated: 2025/03/21 19:49:53 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		len_dst;
	size_t		len_src;

	len_dst = ft_strlen((const char *)dst);
	len_src = ft_strlen(src);
	i = 0;
	if (size <= len_dst)
		len_src += size;
	else
		len_src += len_dst;
	while (src[i] && len_dst + 1 < size)
		dst[len_dst++] = src[i++];
	dst[len_dst] = '\0';
	return (len_src);
}
