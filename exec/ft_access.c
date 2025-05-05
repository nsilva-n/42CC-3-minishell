/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:02:59 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/25 19:05:41 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_access(char **all_paths, char **split_cmd)
{
	int		i;
	char	*name;

	i = -1;
	if (!split_cmd[0])
		return (NULL);
	while (all_paths[++i])
	{
		name = ft_strjoin(all_paths[i], "/");
		name = ft_strjoin_gnl(name, split_cmd[0]);
		if (!access(name, F_OK | X_OK))
			return (name);
		free(name);
	}
	return (NULL);
}
