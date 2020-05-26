/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 07:33:02 by nagresel          #+#    #+#             */
/*   Updated: 2019/12/20 11:03:10 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_conv_handling(const char *str, va_list arg, t_params *flag,
		int *count)
{
	if (*str == 'c')
		ft_format_c(arg, flag, count);
	else if (*str == 's')
		ft_format_s(arg, flag, count);
	else if (*str == 'd' || *str == 'i')
		ft_format_d(arg, flag, count);
	else if (*str == 'u')
		ft_format_u(arg, flag, count);
	else if (*str == 'x' || *str == 'X')
		ft_format_x(arg, flag, count);
	else if (*str == 'p')
		ft_format_p(arg, flag, count);
	else if (*str == '%')
		ft_format_pc(flag, count);
}
