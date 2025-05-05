/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:29:27 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/17 17:19:19 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_cd(char **args, int fd)
{
	char	env_node[4128];
	char	wd[4096];

	if (!args[1]
		|| (!ft_strncmp(args[1], "~/", 2)
			&& ft_strlen(args[1]) == ft_strlen("~/"))
		|| (args[1][0] == '~' && !args[1][1]))
		args[1] = ft_get_node_value(glob()->env, "HOME");
	if (chdir(args[1]))
	{
		ft_fprintf(2, "minishell: cd: %s\n", args[1]);
		glob()->exit_status = 1;
		return ;
	}
	if (!getcwd(wd, sizeof(wd)))
	{
		ft_fprintf(2, "minishell: pwd: ");
		glob()->exit_status = 1;
		return ;
	}
	ft_strlcpy(env_node, "PWD=", sizeof(env_node));
	ft_strlcat(env_node, wd, sizeof(env_node));
	ft_update_pwd();
	ft_export((char *[]){"export", env_node, NULL}, fd, true);
	glob()->exit_status = 0;
}
