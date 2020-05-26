/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:27:19 by nagresel          #+#    #+#             */
/*   Updated: 2020/05/07 18:36:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_join(char *delta, char *buf)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = -1;
	if (!delta && !buf)
		return (0);
	if (delta)
		i = ft_strlen(delta);
	if (!(str = (char *)malloc(sizeof(*str) * (i + ft_strlen(buf) + 1))))
		return (0);
	i = 0;
	while (delta && delta[i])
	{
		str[i] = delta[i];
		i++;
	}
	while (buf && buf[++j])
		str[i + j] = buf[j];
	str[i + j] = '\0';
	if (delta)
		free(delta);
	return (str);
}
