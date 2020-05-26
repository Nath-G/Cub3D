/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:45:49 by nagresel          #+#    #+#             */
/*   Updated: 2019/10/15 14:03:40 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void				*obj;

	if (!(obj = (void *)malloc(count * size)))
		return (NULL);
	ft_bzero(obj, count * size);
	return (obj);
}
