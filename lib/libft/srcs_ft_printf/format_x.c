/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 12:07:36 by nagresel          #+#    #+#             */
/*   Updated: 2019/12/20 13:52:02 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_format_x(va_list arg, t_params *flag, int *count)
{
	int		strlen;
	int		i;
	char	*str;

	i = 0;
	str = ft_utoa_base(va_arg(arg, unsigned int), "0123456789abcdef");
	strlen = ft_strlen(str);
	if (*str == '0' && flag->prec_exist == 1 && flag->prec == 0)
		strlen = 0;
	if (flag->format == 'X')
	{
		while (str[i])
		{
			str[i] = ft_toupper(str[i]);
			i++;
		}
	}
	if (flag->left == 1)
		ft_root_left(str, strlen, flag, count);
	else
		ft_root_right(str, strlen, flag, count);
	free(str);
}
