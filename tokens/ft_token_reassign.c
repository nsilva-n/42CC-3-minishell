/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_reassign.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:06:04 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/16 16:09:37 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*ft_token_reassign(t_token *token)
{
	t_token	*new;

	if (ft_isoperator(token->str, 0)
		&& ft_operator_len(token->str, 0) < (int)ft_strlen(token->str))
		new = ft_extract_operator(token);
	else
		new = ft_extract_word(token);
	new->next->next = token->next;
	if (token->prev)
		token->prev->next = new;
	new->prev = token->prev;
	if (token->next)
		token->next->prev = new->next;
	return (ft_free_token(token), new);
}
