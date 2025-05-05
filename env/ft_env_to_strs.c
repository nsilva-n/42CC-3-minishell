/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_to_strs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:39:00 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/16 13:49:33 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_env_to_strs(t_env *env)
{
	char	**env_chr_ptr;
	t_env	*tmp;
	int		i;
	int		j;

	tmp = env;
	i = ft_count_node(env);
	env_chr_ptr = malloc(sizeof(char *) * (i + 1));
	if (!env_chr_ptr)
		return (NULL);
	tmp = env;
	j = -1;
	while (++j < i)
	{
		env_chr_ptr[j] = ft_strdup(tmp->var);
		if (!env_chr_ptr[j])
			return (ft_free_strs(env_chr_ptr), NULL);
		tmp = tmp->next;
	}
	return (env_chr_ptr[j] = NULL, env_chr_ptr);
}
