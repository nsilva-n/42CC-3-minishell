/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 02:34:51 by mlameira          #+#    #+#             */
/*   Updated: 2025/03/21 19:51:28 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*dest;

	i = -1;
	dest = (const char *)s;
	while (++i < n)
	{
		if (dest[i] == (char)c)
			return ((char *)dest + i);
	}
	return (NULL);
}
