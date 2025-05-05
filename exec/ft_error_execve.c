/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_execve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:18:11 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/16 16:22:28 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_error_execve(char *cmd)
{
	t_env	*temp;
	bool	has_path;

	has_path = false;
	temp = glob()->env;
	while (temp)
	{
		if (!ft_strncmp(temp->key, "PATH", 5))
			has_path = true;
		temp = temp->next;
	}
	if (!has_path)
		ft_fprintf(2, "minishell: %s: No such file or directory\n", cmd);
	else
		ft_fprintf(2, "minishell: %s: command not found\n", cmd);
}
