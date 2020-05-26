/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 07:08:29 by nagresel          #+#    #+#             */
/*   Updated: 2020/04/18 11:40:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFTPRINTF_H
# define _LIBFTPRINTF_H

# include "../libft.h"
# include <stdarg.h>

# define FLAGS "-0.*"
# define INTFORMAT "iuxXd"
# define CONVERSIONS "cspdiuxX%"

typedef struct	s_params
{
	int left;
	int is_zero;
	int width_exist;
	int prec_exist;
	int width;
	int prec;
	int format;
}				t_params;

int				ft_printf(const char *str, ...);
void			ft_putcharcount_fd(const char c, int fd, int *count);
void			ft_putstrcount_fd(const char *str, int fd, int *count);

void			ft_init_struct(t_params *flag);
int				ft_flags_handling(const char *str, va_list arg, t_params *flag);

void			ft_format_c(va_list arg, t_params *flag, int *count);
void			ft_format_d(va_list arg, t_params *flag, int *count);
void			ft_format_p(va_list arg, t_params *flag, int *count);
void			ft_format_pc(t_params *flag, int *count);
void			ft_format_s(va_list arg, t_params *flag, int *count);
void			ft_format_u(va_list arg, t_params *flag, int *count);
void			ft_format_x(va_list arg, t_params *flag, int *count);

void			ft_adjust_prec(t_params *flag, int strlen, int is_neg,
				int *count);
void			ft_adjust_width(t_params *flag, int strlen, int is_neg,
				int *count);
void			ft_root_right(char *str, int strlen, t_params *flag,
				int *count);
void			ft_root_left(char *str, int strlen, t_params *flag, int *count);
int				ft_sign_mngmt(char *str, int *count);

void			ft_conv_handling(const char *str, va_list arg, t_params *flag,
				int *count);
char			*ft_ultoa_base(unsigned long long n, char *base);
char			*ft_utoa_base(unsigned int n, char *base);

#endif
