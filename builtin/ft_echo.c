/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:56:25 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/14 11:57:09 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_echo(char **cmd, int fd)
{
	int		i;
	bool	flag;

	i = 1;
	flag = false;
	if (cmd[1] && ft_isflagn(cmd[1]))
	{
		flag = true;
		i++;
	}
	while (cmd[i] && ft_isflagn(cmd[i]))
		i++;
	while (cmd[i])
	{
		ft_fprintf(fd, "%s", cmd[i]);
		if (cmd[i + 1] && ft_strlen(cmd[i]))
			ft_fprintf(fd, " ");
		i++;
	}
	if (!flag)
		ft_fprintf(fd, "\n");
	glob()->exit_status = 0;
}
