/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retoken.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:50:44 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/16 16:09:34 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*ft_retoken(t_token *token)
{
	t_token	*temp;

	temp = token;
	while (temp->next || ft_isretoken(temp->str))
	{
		if (ft_isretoken(temp->str))
			temp = ft_token_reassign(temp);
		else
			temp = temp->next;
	}
	while (temp->prev)
		temp = temp->prev;
	return (temp);
}
