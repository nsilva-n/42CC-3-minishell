/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:52:34 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/16 15:54:27 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_word_len(char *s)
{
	int	i;

	i = 0;
	while ((!ft_isspace(s[i]) || (ft_isspace(s[i])
				&& ft_isinquote(s, i, false))) && s[i])
		i++;
	return (i);
}
