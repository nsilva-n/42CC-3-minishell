/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:28:04 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/21 12:51:39 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **envp)
{
	(void)av;
	if (ac != 1)
		return (EXIT_FAILURE);
	ft_main_signals();
	ft_init_global(envp);
	while (1)
	{
		glob()->input = readline("minisHELL $>");
		if (!glob()->input)
		{
			ft_fprintf(2, "exit\n");
			break ;
		}
		if (glob()->input && *glob()->input)
		{
			add_history(glob()->input);
			if (ft_main_parse())
				ft_main_exec(glob()->pipes);
			else
				glob()->exit_status = 2;
		}
		ft_free_command();
	}
	return (ft_free(), EXIT_SUCCESS);
}
