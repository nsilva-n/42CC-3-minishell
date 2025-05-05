/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 02:35:59 by mlameira          #+#    #+#             */
/*   Updated: 2025/03/21 19:51:39 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_l;
	t_list	*new_content;
	void	*set;

	if (!lst || !del || !f)
		return (NULL);
	new_l = NULL;
	while (lst)
	{
		set = f(lst->content);
		new_content = ft_lstnew(set);
		if (!new_content)
		{
			del(set);
			ft_lstclear(&new_content, (*del));
			return (new_l);
		}
		ft_lstadd_back(&new_l, new_content);
		lst = lst->next;
	}
	return (new_l);
}
