/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 12:07:36 by nagresel          #+#    #+#             */
/*   Updated: 2019/12/20 12:47:10 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_format_p(va_list arg, t_params *flag, int *count)
{
	int		strlen;
	char	*str;
	char	*temp;

	str = ft_ultoa_base(va_arg(arg, unsigned long long), "0123456789abcdef");
	temp = str;
	str = ft_strjoin("0x", temp);
	free(temp);
	strlen = ft_strlen(str);
	if (flag->left == 1)
		ft_root_left(str, strlen, flag, count);
	else
		ft_root_right(str, strlen, flag, count);
	free(str);
}
