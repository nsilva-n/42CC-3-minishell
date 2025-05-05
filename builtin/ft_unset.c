/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:52:29 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/16 11:16:57 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_unset(char **str, t_env *env)
{
	int	i;

	i = 0;
	if (!env || !str)
	{
		glob()->exit_status = 1;
		return ;
	}
	if (!str[i + 1])
		return ;
	while (str[++i])
		ft_remove_node(str[i]);
	glob()->exit_status = 0;
}
