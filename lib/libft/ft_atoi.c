/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:13:57 by nagresel          #+#    #+#             */
/*   Updated: 2019/10/22 16:04:51 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_nb_is_neg(const char *str)
{
	if (str[0] == '-')
		return (1);
	return (0);
}

static char	*ft_trunq_whitespace(const char *str)
{
	int		i;
	char	*s;

	s = (char *)str;
	i = 0;
	while (*(s + i) == 32 || (*(s + i) >= 9 && *(s + i) <= 13))
		i++;
	return (s + i);
}

static int	ft_convert_str_in_nb(const char *str)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = str[i] - 48 + nb * 10;
		i++;
	}
	return (nb);
}

int			ft_atoi(const char *str)
{
	int nb_is_neg;
	int nb;

	nb = 0;
	str = ft_trunq_whitespace(str);
	nb_is_neg = ft_nb_is_neg(str);
	nb = ft_convert_str_in_nb(str);
	if (nb_is_neg == 1)
		return (-nb);
	return (nb);
}
