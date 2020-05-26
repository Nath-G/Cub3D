/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 09:51:26 by nagresel          #+#    #+#             */
/*   Updated: 2019/10/14 15:49:23 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t dst_len;
	size_t src_len;

	dst_len = 0;
	src_len = 0;
	while (dst[dst_len] && dst_len < dstsize)
		dst_len++;
	while (src[src_len] && src_len + dst_len + 1 < dstsize)
	{
		dst[dst_len + src_len] = src[src_len];
		src_len++;
	}
	if (dst_len < dstsize)
		dst[dst_len + src_len] = '\0';
	return (dst_len + ft_strlen(src));
}
