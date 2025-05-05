/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quoted_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:57:41 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/14 16:33:43 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_quoted_len(char *str, int i)
{
	int		len;

	len = i + 1;
	if (!ft_isquote(str[i]))
		return (-1);
	while (str[len] && str[len] != str[i])
		len++;
	return (len + 1 - i);
}
