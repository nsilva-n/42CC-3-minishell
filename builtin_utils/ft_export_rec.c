/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_rec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:09:15 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/05/01 12:46:01 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_export_rec(t_env *temp, int fd)
{
	int	grade;

	grade = 0;
	while (temp)
	{
		if (!ft_isnext(temp, grade) || !ft_strchr(temp->var, '='))
		{
			if (temp->value && temp->value[0] && temp->exported)
				ft_fprintf(fd, "declare -x %s=\"%s\"\n",
					temp->key, temp->value);
			else if (temp->exported)
				ft_fprintf(fd, "declare -x %s\n", temp->key);
			grade++;
		}
		temp = temp->next;
	}
}
