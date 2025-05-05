/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:10:22 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/05/01 12:42:18 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	ft_isnext(t_env *temp, int grade)
{
	t_env	*start;
	int		i;

	start = glob()->env;
	i = 0;
	while (start)
	{
		if (ft_strcmp(temp->var, start->key))
			i++;
		start = start->next;
	}
	return (i == grade);
}
