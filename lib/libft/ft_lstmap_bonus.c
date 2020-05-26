/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 10:52:52 by nagresel          #+#    #+#             */
/*   Updated: 2020/01/28 15:01:13 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *newlst;
	t_list *newelem;

	(void)(*del);
	newlst = NULL;
	newelem = NULL;
	if (lst && f)
	{
		while (lst)
		{
			if (!(newelem = ft_lstnew(f(lst->content))))
			{
				ft_lstclear(&newlst, *del);
				return (NULL);
			}
			ft_lstadd_front(&newlst, newelem);
			lst = lst->next;
		}
	}
	return (newlst);
}
