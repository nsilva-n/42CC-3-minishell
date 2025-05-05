/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:56:39 by mlameira          #+#    #+#             */
/*   Updated: 2025/03/21 19:47:43 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_dec(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_dec(n);
	dest = (char *)ft_calloc(i + 1, sizeof(char));
	if (!dest)
		return ((void *)0);
	if (n == 0)
		dest[0] = '0';
	if (n < 0)
	{
		n = -n;
		dest[0] = '-';
	}
	while (n)
	{
		dest[--i] = n % 10 + '0';
		n /= 10;
	}
	return (dest);
}

/*
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	ft_putstr_fd(ft_itoa(42), 1);
	printf("%s", ft_itoa(42));
}
*/
