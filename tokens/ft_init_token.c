/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:54:02 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/16 12:50:17 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*ft_init_token(char *str)
{
	t_token	*new_t;
	int		str_len;

	new_t = (t_token *)malloc(sizeof(t_token) + 1);
	if (!new_t)
		return (NULL);
	str_len = ft_strlen(str);
	new_t->str = malloc(str_len + 1);
	if (!new_t->str)
		return (free(new_t), NULL);
	ft_strlcpy(new_t->str, str, str_len + 1);
	if (new_t->str)
		new_t->type = ft_get_token_type(str);
	else
		new_t->type = -1;
	return (new_t->next = NULL, new_t->prev = NULL, new_t->index = -1, new_t);
}
