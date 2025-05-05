/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:06:19 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/17 17:42:01 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_export(char **args, int fd, bool flag)
{
	int	i;

	i = 0;
	glob()->exit_status = 0;
	if (!flag)
		i--;
	if (!args[1] && flag)
	{
		if (glob()->env)
			ft_export_rec(glob()->env, fd);
		return ;
	}
	while (args[++i])
	{
		if (ft_isvalidexport(args[i]) && flag)
		{
			ft_fprintf(2, "minishell: export \"%s\": not a valid identifier\n",
				args[i]);
			glob()->exit_status = 1;
		}
		else
			ft_node_addback(glob()->env, ft_init_node(args[i]), flag);
	}
}
