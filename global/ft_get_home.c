/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_home.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:36:36 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/14 11:38:23 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_get_home(void)
{
	char	*wd;
	char	*home;
	int		i;
	int		count;

	i = -1;
	count = 0;
	wd = getcwd(NULL, 0);
	while (wd[++i])
	{
		if (wd[i] == '/')
			count++;
		if (count == 3)
			break ;
	}
	home = malloc(i + 1);
	home[i] = '\0';
	while (--i >= 0)
		home[i] = wd[i];
	return (free(wd), home);
}
