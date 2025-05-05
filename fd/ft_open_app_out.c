/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_app_out.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:11:06 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/05/01 13:38:14 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	ft_open_app_out(char *str, t_pipex *pipes)
{
	if (!str)
		return (false);
	if (!*str)
		return (glob()->exit_status = 1, pipes->bad_command = true,
			ft_fprintf(2, "minishell: No such file or directory\n"), false);
	pipes->out_fd = open(str, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (pipes->out_fd == -1)
		return (glob()->exit_status = 1, pipes->bad_command = true,
			ft_fprintf(2, "minishell: %s\n", str), false);
	return (true);
}
