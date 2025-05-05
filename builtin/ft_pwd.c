/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:14:28 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/14 11:28:33 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_pwd(int fd)
{
	char	*wd;

	wd = getcwd(NULL, 0);
	if (!wd)
		wd = ft_strdup(glob()->pwd);
	if (wd)
	{
		ft_fprintf(fd, "%s\n", wd);
		free(wd);
		glob()->exit_status = 0;
	}
	else
		ft_error("minishell: pwd", 1);
}
