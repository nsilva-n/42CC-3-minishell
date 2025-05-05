/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_input_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:19:49 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/22 13:50:40 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	ft_open_input_file(char *str, t_pipex *pipes)
{
	pipes->in_fd = open(str, O_RDONLY);
	if (pipes->in_fd == -1)
		return (pipes->bad_command = true, pipes->in_fd = 0, false);
	return (true);
}
