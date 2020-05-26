/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_handling_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 10:26:38 by nagresel          #+#    #+#             */
/*   Updated: 2020/05/07 18:26:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_sign_mngmt(char *str, int *count)
{
	if (*str != '-')
		return (0);
	ft_putcharcount_fd('-', 1, count);
	return (1);
}

void	ft_adjust_width(t_params *flag, int strlen,
		int is_neg, int *count)
{
	int		i;
	int		end;
	char	c;

	c = ' ';
	end = strlen;
	if (flag->prec > strlen - is_neg)
		end = flag->prec + is_neg;
	if (flag->is_zero == 1)
		c = '0';
	i = 0;
	if (flag->width_exist == 1 && flag->width > end)
	{
		while (i < flag->width - end)
		{
			ft_putcharcount_fd(c, 1, count);
			i++;
		}
	}
}

void	ft_adjust_prec(t_params *flag, int strlen, int is_neg, int *count)
{
	int		i;

	i = 0;
	if (flag->prec_exist == 1 &&
			flag->prec > (strlen - is_neg))
	{
		while (i < flag->prec - (strlen - is_neg))
		{
			ft_putcharcount_fd('0', 1, count);
			i++;
		}
	}
}

void	ft_root_left(char *str, int strlen, t_params *flag, int *count)
{
	int is_neg;

	is_neg = 0;
	if (*str == '-')
		is_neg = 1;
	ft_sign_mngmt(str, count);
	ft_adjust_prec(flag, strlen, is_neg, count);
	if (!(flag->prec_exist == 1 && flag->prec == 0 && *str == '0' &&
				flag->format != 'p'))
		ft_putstrcount_fd(str + is_neg, 1, count);
	ft_adjust_width(flag, strlen, is_neg, count);
}

void	ft_root_right(char *str, int strlen, t_params *flag, int *count)
{
	int is_neg;

	is_neg = 0;
	if (*str == '-')
		is_neg = 1;
	if (flag->is_zero == 1)
		ft_sign_mngmt(str, count);
	ft_adjust_width(flag, strlen, is_neg, count);
	if (flag->is_zero == 0)
		ft_sign_mngmt(str, count);
	ft_adjust_prec(flag, strlen, is_neg, count);
	if (!(flag->prec_exist == 1 && flag->prec == 0 && *str == '0' &&
				flag->format != 'p'))
		ft_putstrcount_fd(str + is_neg, 1, count);
}
