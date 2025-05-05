/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:26:28 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/14 11:27:15 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strs_count(char **strs)
{
	int	count;

	count = 0;
	if (!strs)
		return (count);
	while (strs[count])
		count++;
	return (count);
}
