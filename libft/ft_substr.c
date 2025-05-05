/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:03:39 by mlameira          #+#    #+#             */
/*   Updated: 2025/04/20 09:40:56 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub_s;
	unsigned int	len_subs;
	size_t			len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start < len_s)
		len_subs = len_s - start;
	else
		len_subs = 0;
	if (len_subs > len)
		len_subs = len;
	if (len_subs == 0)
		return (ft_strdup(""));
	sub_s = ft_calloc(len_subs + 1, sizeof(char));
	if (!sub_s)
		return (NULL);
	ft_strlcpy_nobar(sub_s, &s[start], len_subs + 1);
	return (sub_s);
}
