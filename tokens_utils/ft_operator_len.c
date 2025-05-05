/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isoperator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:19:17 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/16 12:58:34 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_operator_len(char *str, int i)
{
	if (str[i] == '<' && str[i + 1] == '<')
		return (2);
	if (str[i] == '>' && str[i + 1] == '>')
		return (2);
	if (str[i] == '|' || str[i] == '>' || str[i] == '<')
		return (1);
	return (0);
}
