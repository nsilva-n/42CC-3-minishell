/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islonglong.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:11:34 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/14 18:11:41 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	is_in_long_long_range(char *str)
{
	unsigned long long	threshold;
	unsigned long long	n;
	int					digit;

	threshold = (unsigned long long)LLONG_MAX;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			threshold++;
		str++;
	}
	n = 0;
	while (ft_isdigit(*str))
	{
		digit = *str - '0';
		if (n > (threshold - digit) / 10)
			return (false);
		n = n * 10 + digit;
		str++;
	}
	return (true);
}
