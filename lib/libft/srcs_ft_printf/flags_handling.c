/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 07:53:28 by nagresel          #+#    #+#             */
/*   Updated: 2019/12/20 10:52:01 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_check_format(const char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

static void	ft_exceptions_mngmt(t_params *flag)
{
	if (flag->width_exist && flag->width < 0)
	{
		flag->left = 1;
		flag->width *= -1;
	}
	if (flag->prec_exist && flag->prec < 0)
		flag->prec_exist = 0;
	if (flag->left == 1 && flag->is_zero == 1)
		flag->is_zero = 0;
	if (flag->is_zero == 1 && ft_check_format(flag->format, INTFORMAT) &&
			flag->prec_exist == 1 && flag->width > flag->prec)
		flag->is_zero = 0;
	if (flag->format == '%' || flag->format == 'p')
	{
		flag->prec_exist = 0;
		flag->prec = 0;
	}
}

static void	ft_set_struct_digit(const char *str, va_list arg, t_params *flag)
{
	if (ft_isdigit(*str) && flag->prec_exist == 0 && flag->width == -1)
	{
		flag->width_exist = 1;
		flag->width = (*str) - 48;
	}
	else if (ft_isdigit(*str) && !flag->prec_exist && flag->width != -1)
		flag->width = (flag->width * 10) + (*str) - 48;
	else if (ft_isdigit(*str) == 1 && flag->prec_exist == 1 && flag->prec == -1)
		flag->prec = (*str) - 48;
	else if (ft_isdigit(*str) && flag->prec_exist == 1 && flag->prec != -1)
		flag->prec = (flag->prec * 10) + (*str) - 48;
	else if (*str == '*' && flag->prec_exist == 0)
	{
		flag->width_exist = 1;
		flag->width = va_arg(arg, int);
	}
	else if (*str == '*' && flag->prec_exist == 1)
	{
		flag->prec = va_arg(arg, int);
		if (flag->prec < 0)
			flag->prec_exist = 0;
	}
}

static void	ft_set_struct(const char *str, va_list arg, t_params *flag, int end)
{
	flag->format = str[end];
	while (*str != flag->format)
	{
		if (*str == '-')
			flag->left = 1;
		else if (*str == '0' && !flag->width_exist && !flag->prec_exist)
			flag->is_zero = 1;
		else if (*str == '.')
			flag->prec_exist = 1;
		else
			ft_set_struct_digit(str, arg, flag);
		str++;
	}
	ft_exceptions_mngmt(flag);
}

int			ft_flags_handling(const char *str, va_list arg, t_params *flag)
{
	int end;

	end = 0;
	while (str[end] && (ft_check_format(str[end], FLAGS) ||
			ft_isdigit(str[end])))
		end++;
	ft_set_struct(str, arg, flag, end);
	return (end);
}
