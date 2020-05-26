/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 12:07:36 by nagresel          #+#    #+#             */
/*   Updated: 2019/12/20 13:50:20 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_format_u(va_list arg, t_params *flag, int *count)
{
	int		strlen;
	char	*str;

	str = ft_utoa_base(va_arg(arg, unsigned int), "0123456789");
	strlen = ft_strlen(str);
	if (*str == '0' && flag->prec_exist == 1 && flag->prec == 0)
		strlen = 0;
	if (flag->left == 1)
		ft_root_left(str, strlen, flag, count);
	else
		ft_root_right(str, strlen, flag, count);
	free(str);
}
