/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalidexport.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:13:00 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/14 13:04:46 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	ft_isvalidexport(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (false);
	if (str[0] == '=' || ft_isdigit(str[0])
		|| (!ft_isalpha(str[0]) && str[0] != '_'))
		return (true);
	while (++i >= 0 && str[i] && str[i] != '=')
		if (!ft_isalpha(str[i]) && !ft_isdigit(str[i]) && str[i] != '_')
			return (true);
	return (false);
}
