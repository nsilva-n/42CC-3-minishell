/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_addback.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:12:20 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/14 14:13:39 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_token_addback(t_token *token, t_token *add)
{
	t_token	*temp;

	temp = token;
	while (temp->next)
		temp = temp->next;
	add->prev = temp;
	temp->next = add;
}
