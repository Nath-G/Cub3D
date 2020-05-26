/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_handling_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 10:40:44 by nagresel          #+#    #+#             */
/*   Updated: 2019/12/20 10:53:45 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_init_struct(t_params *flag)
{
	flag->left = 0;
	flag->is_zero = 0;
	flag->width_exist = 0;
	flag->width = -1;
	flag->prec_exist = 0;
	flag->prec = 0;
	flag->format = 0;
}
