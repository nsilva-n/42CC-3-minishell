/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_std_out.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:12:57 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/05/01 13:38:11 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	ft_open_std_out(char *str, t_pipex *pipes)
{
	if (!str)
		return (false);
	if (!*str)
		return (ft_fprintf(2, "minishell: No such file or directory\n"), \
			glob()->exit_status = 1, pipes->bad_command = true, false);
	pipes->out_fd = open(str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipes->out_fd == -1)
		return (ft_fprintf(2, "minishell: %s\n", str), glob()->exit_status = 1,
			pipes->bad_command = true, false);
	return (true);
}
