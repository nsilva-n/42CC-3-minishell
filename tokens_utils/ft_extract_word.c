/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_word.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:24:41 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/16 15:54:56 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*ft_extract_word(t_token *token)
{
	t_token	*new_first;
	t_token	*new_second;
	char	*help;
	int		i;

	i = 0;
	while (!ft_isoperator(token->str, i)
		|| (ft_isoperator(token->str, i) && ft_isinquote(token->str, i, false)))
		i++;
	help = ft_substr(token->str, 0, i);
	new_first = ft_init_token(help);
	free(help);
	help = ft_substr(token->str, i, ft_strlen(token->str));
	new_second = ft_init_token(help);
	new_first->next = new_second;
	new_first->next->prev = new_first;
	return (free(help), new_first);
}
