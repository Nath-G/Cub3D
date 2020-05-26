/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:50:51 by nagresel          #+#    #+#             */
/*   Updated: 2019/10/11 12:04:57 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	if (c == '\0')
	{
		while (*str)
			str++;
		return (str);
	}
	while (str[i])
		i++;
	while (i > 0)
	{
		if (*(str + i - 1) == c)
			return (str + i - 1);
		i--;
	}
	return (0);
}
