/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:59:49 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/04/14 14:01:33 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	ft_error_env(char *str, int err, int fd)
{
	ft_fprintf(fd, "env: '%s': no such file or directory\n", str);
	return (glob()->exit_status = err, false);
}
