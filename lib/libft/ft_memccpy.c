/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:56:51 by nagresel          #+#    #+#             */
/*   Updated: 2019/10/10 15:55:31 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n > 0)
	{
		*(unsigned char*)dst = *(unsigned char*)src;
		dst++;
		if (*(unsigned char *)src == (unsigned char)c)
			return (dst);
		n--;
		src++;
	}
	return (0);
}
