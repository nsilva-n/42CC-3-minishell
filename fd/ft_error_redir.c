/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:09:21 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/14 16:10:10 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	ft_error_redir(t_token *token)
{
	if (!token || !token->str || !*token->str)
		return (ft_fprintf(2, "error near redirections\n"), false);
	if (!token->prev)
		return (ft_fprintf(2, "error near newline\n"), false);
	return (ft_fprintf(2, "error near \"%s\"\n", &token->str[0]), false);
}
