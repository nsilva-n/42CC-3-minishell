/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:27:42 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/05/01 13:50:03 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	ft_main_parse(void)
{
	if (ft_isinquote(glob()->input, ft_strlen(glob()->input), false))
		return (ft_fprintf(2, "Syntax error\n"), false);
	glob()->token = ft_input_split_to_token(ft_token_split(glob()->input));
	if (!glob()->token)
		return (false);
	glob()->token = ft_retoken(glob()->token);
	ft_expand_nodes(glob()->token, true);
	ft_tilde_loop(glob()->token);
	if (!ft_isvalidfirstparse(glob()->token))
		return (false);
	return (ft_tokens_to_pipe(glob()->token),
		ft_remove_pipe_quotes(glob()->pipes),
		ft_free_new_input(glob()->input), true);
}
