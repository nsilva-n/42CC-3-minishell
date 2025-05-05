/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_signaled.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:43:55 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/14 14:44:16 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_signaled(int status)
{
	if (WTERMSIG(status) == 2 && !glob()->signaled)
		ft_printf("\n");
	else if (WTERMSIG(status) == 3 && !glob()->signaled)
		ft_printf("Quit (no core dump)\n");
	if ((WTERMSIG(status) == 2 || WTERMSIG(status) == 3) && !glob()->signaled)
		glob()->signaled = true;
	glob()->exit_status = 128 + WTERMSIG(status);
}
