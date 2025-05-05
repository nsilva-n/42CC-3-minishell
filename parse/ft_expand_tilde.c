/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_tilde.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:56:50 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/14 17:57:54 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_expand_tilde(t_token *token)
{
	char	*expand;
	char	*ret;
	int		ret_i;
	int		t_i;
	int		exp_i;

	ret_i = 0;
	t_i = 1;
	exp_i = 0;
	expand = ft_strdup(glob()->home);
	ret = malloc(ft_strlen(expand) + ft_strlen(token->str) + 1);
	while (expand[exp_i])
		ret[ret_i++] = expand[exp_i++];
	while (token->str[t_i])
		ret[ret_i++] = token->str[t_i++];
	ret[ret_i] = '\0';
	free(expand);
	free(token->str);
	token->str = ret;
}
