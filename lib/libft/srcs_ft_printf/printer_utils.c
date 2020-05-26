/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 07:23:31 by nagresel          #+#    #+#             */
/*   Updated: 2019/12/19 11:38:04 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putcharcount_fd(const char c, int fd, int *count)
{
	write(fd, &c, 1);
	*count += 1;
}

void	ft_putstrcount_fd(const char *str, int fd, int *count)
{
	int strlen;

	strlen = ft_strlen(str);
	write(fd, str, strlen);
	*count += strlen;
}
