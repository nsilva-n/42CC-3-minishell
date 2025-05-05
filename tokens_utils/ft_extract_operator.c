/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_operator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:25:49 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/16 12:58:45 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*ft_extract_operator(t_token *t)
{
	t_token	*new_t;
	t_token	*next_t;
	char	*help;

	help = ft_substr(t->str, 0, ft_operator_len(t->str, 0));
	new_t = ft_init_token(help);
	free(help);
	help = ft_substr(t->str, ft_operator_len(t->str, 0), ft_strlen(t->str));
	next_t = ft_init_token(help);
	new_t->next = next_t;
	next_t->prev = new_t;
	return (free(help), new_t);
}
