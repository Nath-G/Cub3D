/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 07:45:21 by nagresel          #+#    #+#             */
/*   Updated: 2019/12/19 11:28:20 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_format_c(va_list arg, t_params *flag, int *count)
{
	int i;

	i = flag->width - 1;
	if (flag->left == 1 && flag->width > 1)
	{
		ft_putcharcount_fd(va_arg(arg, int), 1, count);
		while (i-- > 0)
			ft_putcharcount_fd(' ', 1, count);
	}
	else if (flag->width > 1)
	{
		while (i-- > 0)
			ft_putcharcount_fd(' ', 1, count);
		ft_putcharcount_fd(va_arg(arg, int), 1, count);
	}
	else
		ft_putcharcount_fd(va_arg(arg, int), 1, count);
}
