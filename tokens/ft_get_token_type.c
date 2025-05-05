/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_token_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:29:19 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/17 16:57:06 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_get_token_type(char *str)
{
	if (!str)
		return (-1);
	if (str[0] == '>' && !str[1])
		return (RED_OUT);
	if (str[0] == '>' && str[1] == '>' && !str[2])
		return (RED_APP);
	if (str[0] == '<' && !str[1])
		return (RED_IN);
	if (str[0] == '<' && str[1] == '<' && !str[2])
		return (HERE_DOC);
	if (str[0] == '|' && !str[1])
		return (PIPE);
	return (WORD);
}
