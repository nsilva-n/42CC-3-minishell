/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_special_node.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:23:23 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/16 15:05:25 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_get_special_node(char *key)
{
	if (!ft_strncmp(key, "$", ft_strlen(key)))
		return (ft_itoa(ft_get_pid()));
	if (!ft_strncmp(key, "?", ft_strlen(key)))
		return (ft_itoa(glob()->exit_status));
	return (ft_strdup(""));
}
