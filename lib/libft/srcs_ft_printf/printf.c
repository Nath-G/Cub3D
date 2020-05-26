/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 07:07:38 by nagresel          #+#    #+#             */
/*   Updated: 2019/12/19 13:10:16 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *str, ...)
{
	int			i;
	int			count;
	va_list		arg;
	t_params	flag;

	i = 0;
	count = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] != '%')
			ft_putcharcount_fd(str[i], 1, &count);
		else
		{
			ft_init_struct(&flag);
			i += ft_flags_handling(str + i + 1, arg, &flag) + 1;
			ft_conv_handling(str + i, arg, &flag, &count);
		}
		i++;
	}
	va_end(arg);
	return (count);
}
