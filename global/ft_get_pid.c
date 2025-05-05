/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:46:47 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/25 19:08:22 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

pid_t	ft_get_pid(void)
{
	char	*line;
	int		fd;
	char	*str;
	pid_t	res;

	fd = open("/proc/self/status", O_RDONLY);
	if (fd == -1)
		return (0);
	line = ft_get_next_line(fd);
	while (line)
	{
		if (!ft_strncmp(line, "Pid:", 4))
		{
			str = ft_substr(line, 5, ft_strlen(line) - 5);
			res = ft_atoi(str);
			return (close(fd), free(line), free(str), res);
		}
		free(line);
		line = ft_get_next_line(fd);
	}
	return (-1);
}
