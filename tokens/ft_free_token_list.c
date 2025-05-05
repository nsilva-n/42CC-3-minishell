/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_token_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:27:48 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/16 16:12:53 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_free_token_list(t_token *token)
{
	t_token	*temp;

	if (!token)
		return ;
	temp = token;
	while (temp)
	{
		token = temp->next;
		ft_free_token(temp);
		temp = token;
	}
}
