/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:59:23 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/21 16:24:12 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_exit_builtin(char **args)
{
	ft_fprintf(2, "exit\n");
	if (!args[1])
		ft_exit(EXIT_SUCCESS);
	if (args[2] && ft_isnumber(args[1]))
	{
		ft_fprintf(2, "minishell: exit: too many arguments\n");
		return ;
	}
	if (!ft_isnumber(args[1]) || !is_in_long_long_range(args[1]))
	{
		ft_fprintf(2, "minishell: exit: %s: numeric argument required\n",
			args[1]);
		ft_exit(2);
	}
	ft_exit((int)(ft_atoll(args[1]) % 256));
}
