/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_heredoc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:27:40 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/29 13:39:29 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_process_heredoc(char *help, char *tmp)
{
	char	*temp;
	char	*temp2;

	if (!help)
		return (NULL);
	if (*help)
		help = ft_heredoc_expand(help);
	if (tmp)
		temp = ft_strjoin(tmp, help);
	else
		temp = ft_strdup(help);
	temp2 = ft_strjoin(temp, "\n");
	return (free(help), free(temp), free(tmp), temp2);
}
