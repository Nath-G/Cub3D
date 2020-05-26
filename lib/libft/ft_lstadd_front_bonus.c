/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:22:58 by nagresel          #+#    #+#             */
/*   Updated: 2020/01/28 15:00:49 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	t_list *temp;

	temp = *alst;
	if (*alst == NULL)
		*alst = new;
	else
	{
		*alst = new;
		new->next = temp;
	}
}
