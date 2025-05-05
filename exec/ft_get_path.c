/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:36:37 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/21 14:03:19 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_get_path(char *cmd, char **env)
{
	int		i;
	char	**all_paths;
	char	*name;
	char	**split_cmd;

	i = -1;
	name = NULL;
	while (env[++i])
		if (!ft_strncmp(env[i], "PATH=", 5))
			break ;
	if (!env[i])
		return (cmd);
	all_paths = ft_split(env[i] + 5, ':');
	split_cmd = ft_split(cmd, ' ');
	if (!all_paths || !split_cmd)
		return (ft_fprintf(2, "Malloc failed\n"), NULL);
	name = ft_access(all_paths, split_cmd);
	if (!name)
		return (ft_free_strs(all_paths), ft_free_strs(split_cmd), cmd);
	return (ft_free_strs(split_cmd), name);
}
