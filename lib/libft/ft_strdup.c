/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:07:40 by nagresel          #+#    #+#             */
/*   Updated: 2019/10/14 16:43:46 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	if (!(str = (char *)malloc(sizeof(*str) * ft_strlen(s1) + 1)))
		return (NULL);
	i = 0;
	while (*(s1 + i))
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
