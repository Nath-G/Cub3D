/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:36:40 by nagresel          #+#    #+#             */
/*   Updated: 2019/10/11 15:50:44 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int				i;
	unsigned char	*ptdst;
	unsigned char	*ptsrc;

	if (!dst && !src)
		return (NULL);
	ptsrc = (unsigned char*)src;
	ptdst = (unsigned char*)dst;
	i = 0;
	while (n > 0)
	{
		ptdst[i] = ptsrc[i];
		i++;
		n--;
	}
	return (dst);
}
