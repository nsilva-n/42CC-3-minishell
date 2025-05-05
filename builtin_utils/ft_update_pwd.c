/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_pwd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:09:24 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/14 12:11:29 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_update_pwd(void)
{
	char	*temp;

	temp = getcwd(NULL, 0);
	if (temp)
	{
		free(glob()->pwd);
		glob()->pwd = temp;
	}
}
