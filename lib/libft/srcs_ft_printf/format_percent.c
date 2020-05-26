/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 12:07:36 by nagresel          #+#    #+#             */
/*   Updated: 2019/12/20 10:57:19 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_format_pc(t_params *flag, int *count)
{
	if (flag->left == 1)
		ft_root_left("%", 1, flag, count);
	else
		ft_root_right("%", 1, flag, count);
}
