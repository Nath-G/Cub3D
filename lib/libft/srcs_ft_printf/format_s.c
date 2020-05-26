/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 13:51:08 by nagresel          #+#    #+#             */
/*   Updated: 2019/12/20 10:25:25 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_adjust_width_s(t_params *flag, size_t strlen, int *count)
{
	size_t	i;

	i = 0;
	if (flag->prec_exist == 0 && flag->width_exist == 1 &&
			(unsigned long)flag->width > strlen)
	{
		while (i < (unsigned long)flag->width - strlen)
		{
			ft_putcharcount_fd(' ', 1, count);
			i++;
		}
	}
}

static void	ft_adjust_prec_s(t_params *flag, int strlen, int *count)
{
	int i;

	i = 0;
	if (flag->prec_exist && flag->prec == '0')
		;
	else if (flag->width_exist == 1 && flag->prec_exist == 1 &&
			flag->width > strlen &&
			flag->prec > strlen)
	{
		while (i < flag->width - strlen)
		{
			ft_putcharcount_fd(' ', 1, count);
			i++;
		}
	}
	else if (flag->width_exist == 1 && flag->prec_exist == 1 &&
			flag->width > flag->prec)
	{
		while (i < flag->width - flag->prec)
		{
			ft_putcharcount_fd(' ', 1, count);
			i++;
		}
	}
}

static void	ft_print_s(char *s, t_params *flag, int slen, int *count)
{
	if (flag->left == 1)
	{
		if (!(flag->prec_exist && flag->prec == '0'))
			ft_putstrcount_fd(s, 1, count);
	}
	ft_adjust_width_s(flag, slen, count);
	ft_adjust_prec_s(flag, slen, count);
	if (!(flag->left == 1))
	{
		if (!(flag->prec_exist && flag->prec == '0'))
			ft_putstrcount_fd(s, 1, count);
	}
}

void		ft_format_s(va_list arg, t_params *flag, int *count)
{
	int		strlen;
	char	*str;
	char	*s;

	str = va_arg(arg, char *);
	if (!str)
		str = "(null)";
	else if (!*str)
		str = "";
	strlen = ft_strlen(str);
	s = ft_strdup(str);
	if (flag->prec_exist && flag->prec < strlen)
		s[flag->prec] = '\0';
	ft_print_s(s, flag, strlen, count);
	free(s);
}
