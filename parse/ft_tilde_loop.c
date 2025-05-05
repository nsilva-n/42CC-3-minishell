/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tilde_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:55:03 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/16 12:48:02 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_tilde_loop(t_token *token)
{
	while (token->next || token->str[0] == '~')
	{
		if (token->str[0] == '~')
			ft_expand_tilde(token);
		else
			token = token->next;
	}
}
