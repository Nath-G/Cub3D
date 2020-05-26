/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 11:37:58 by nagresel          #+#    #+#             */
/*   Updated: 2020/04/18 11:11:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_count(unsigned long long n, unsigned int lenbase)
{
	int i;

	i = 0;
	while (n > 0)
	{
		i++;
		n = n / lenbase;
	}
	return (i);
}

static char	*ft_conv_base(unsigned long long n, const char *base, int strlen,
		char *str)
{
	unsigned long	lenbase;

	lenbase = ft_strlen(base);
	while (strlen > 0)
	{
		str[strlen - 1] = base[n % lenbase];
		n = n / lenbase;
		strlen--;
	}
	return (str);
}

char		*ft_ultoa_base(unsigned long long n, char *base)
{
	char	*str;
	int		strlen;

	strlen = ft_strlen_count(n, ft_strlen(base));
	if (n == 0)
		strlen = 1;
	if (!(str = (char *)malloc(sizeof(*str) * (strlen + 1))))
		return (NULL);
	ft_bzero(str, strlen);
	str[strlen] = '\0';
	str = ft_conv_base(n, base, strlen, str);
	return (str);
}
