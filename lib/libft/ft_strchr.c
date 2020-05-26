/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:21:22 by nagresel          #+#    #+#             */
/*   Updated: 2019/10/11 11:45:15 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char *str;

	str = (char *)s;
	if (c == '\0')
	{
		while (*str)
			str++;
		return (str);
	}
	else
	{
		while (*str)
		{
			if (*str == c)
				return (str);
			str++;
		}
	}
	return (0);
}
