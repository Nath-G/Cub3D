/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:15:40 by nagresel          #+#    #+#             */
/*   Updated: 2019/10/22 15:22:40 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(char const c, char const *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		end;
	char	*strtrim;

	if (!s1)
		return (NULL);
	while (*s1 && ft_isinset(*s1, set))
		s1++;
	end = 0;
	while (s1[end])
		end++;
	while (end > 0 && s1[end - 1] && ft_isinset(s1[end - 1], set))
		end--;
	if (!(strtrim = (char *)malloc(sizeof(*strtrim) * (end + 1))))
		return (NULL);
	i = 0;
	while (*s1 && i < end)
		strtrim[i++] = *s1++;
	strtrim[i] = '\0';
	return (strtrim);
}
