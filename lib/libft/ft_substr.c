/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 11:39:09 by nagresel          #+#    #+#             */
/*   Updated: 2019/10/22 16:04:32 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;

	if (!s)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	if (ft_strlen(s) <= start)
	{
		*str = '\0';
		return (str);
	}
	i = 0;
	while (*s && *(s + i + start) && i < len)
	{
		*(str + i) = *(s + start + i);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}
