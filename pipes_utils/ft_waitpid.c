/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_waitpid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:34:06 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/22 14:09:35 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_waitpid(int pid)
{
	int	status;

	while (waitpid(pid, &status, 0) == -1)
	{
		if (errno == EINTR)
			continue ;
		ft_error("waitpid", 1);
		return ;
	}
	if (WIFEXITED(status))
		glob()->exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		ft_signaled(status);
	else
		glob()->exit_status = 1;
}
