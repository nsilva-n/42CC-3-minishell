/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:38:11 by mlameira          #+#    #+#             */
/*   Updated: 2025/03/21 19:51:08 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*srce;
	char	*dst;
	int		i;

	i = (int)n;
	srce = (char *)src;
	dst = (char *)dest;
	if (srce < dst)
	{
		while (--i >= 0)
			dst[i] = srce[i];
	}
	else
		ft_memcpy(dest, src, n);
	return ((void *)dst);
}
