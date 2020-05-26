/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:20:12 by nagresel          #+#    #+#             */
/*   Updated: 2019/12/20 13:50:22 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_format_d(va_list arg, t_params *flag, int *count)
{
	int		strlen;
	char	*str;

	str = ft_itoa(va_arg(arg, int));
	strlen = ft_strlen(str);
	if (*str == '0' && flag->prec_exist == 1 && flag->prec == 0)
		strlen = 0;
	if (flag->left == 1)
		ft_root_left(str, strlen, flag, count);
	else
		ft_root_right(str, strlen, flag, count);
	free(str);
}
