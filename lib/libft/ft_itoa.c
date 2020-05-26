/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:57:22 by nagresel          #+#    #+#             */
/*   Updated: 2019/10/22 14:29:46 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_count(int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int	ft_div(int len)
{
	int div;

	div = 1;
	while (len > 1)
	{
		div = div * 10;
		len--;
	}
	return (div);
}

static char	*ft_nb_convert_in_str(char *str, int strlen, int n)
{
	int i;
	int len;
	int div;

	len = strlen;
	i = 0;
	div = 1;
	if (n < 0)
	{
		len--;
		str[i++] = '-';
		n = -n;
	}
	div = ft_div(len);
	while (i < strlen)
	{
		str[i++] = n / div + 48;
		n = (n - (n / div) * div);
		div = div / 10;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	int		strlen;
	char	*str;

	strlen = 0;
	strlen = ft_strlen_count(n);
	if (n == -2147483648)
	{
		str = ft_strdup("-2147483648");
		return (str);
	}
	if (!(str = (char *)malloc(sizeof(*str) * (strlen + 1))))
		return (NULL);
	str = ft_nb_convert_in_str(str, strlen, n);
	return (str);
}
