/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:48:30 by nagresel          #+#    #+#             */
/*   Updated: 2020/01/28 15:00:45 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last_item;

	last_item = NULL;
	if (!*alst)
		*alst = new;
	else
	{
		last_item = ft_lstlast(*alst);
		last_item->next = new;
		new->next = NULL;
	}
}
