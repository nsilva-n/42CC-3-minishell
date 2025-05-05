/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspecialexpand.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:03:38 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/16 12:40:51 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	ft_isspecialexpand(char *key)
{
	if (!*key)
		return (false);
	return (!ft_strncmp(key, "$", ft_strlen(key))
		|| !ft_strncmp(key, "?", ft_strlen(key)));
}
