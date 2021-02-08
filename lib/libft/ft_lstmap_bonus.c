/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 00:20:19 by safernan          #+#    #+#             */
/*   Updated: 2019/10/28 20:12:34 by safernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// does not work [KO]
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*save;
	t_list		*out;
	t_list		*i;

	if (!lst)
		return (lst);
	if (!(out = ft_lstnew(f(lst->content))))
		return (NULL);
	i = lst;
	save = out;
	while (1)
	{
		if (!(out->next = ft_lstnew(f(i->content))))
		{
			ft_lstclear(&save, del);
			return (NULL);
		}
		i = i->next;
		out = out->next;
		if (!i || !out)
			break ;
	}
	return (save);
}
