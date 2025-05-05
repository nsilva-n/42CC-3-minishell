/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:48:46 by mlameira          #+#    #+#             */
/*   Updated: 2025/04/25 14:00:34 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(const char *s, char c)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (*s && *s == c)
		s++;
	while (s[i])
	{
		if (!i)
			size++;
		else if (s[i - 1] == c && s[i] != c)
			size++;
		i++;
	}
	return (size);
}

static size_t	ft_word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	ft_free(char **dest, int i)
{
	while (--i >= 0)
		free(dest[i]);
	free(dest);
}

char	**ft_split(char const *s, char c)
{
	char		**dest;
	size_t		len_dest;
	int			i;

	if (!s)
		return (NULL);
	len_dest = ft_count_words(s, c);
	dest = malloc(sizeof(char *) * (len_dest + 1));
	if (!dest)
		return (NULL);
	i = -1;
	while (++i < (int)len_dest)
	{
		while (*s && *s == c)
			s++;
		dest[i] = ft_substr(s, 0, ft_word_len(s, c));
		if (!dest[i])
		{
			ft_free(dest, i);
			return (NULL);
		}
		s += ft_word_len(s, c) + 1;
	}
	dest[len_dest] = NULL;
	return (dest);
}
