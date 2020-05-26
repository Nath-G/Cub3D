/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:29:07 by nagresel          #+#    #+#             */
/*   Updated: 2020/05/07 18:08:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_str_hasreturn(char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

static char	*ft_get_line(char *delta)
{
	int		i;
	char	*s;

	i = 0;
	while (delta[i] && delta[i] != '\n')
		i++;
	if (!(s = (char *)malloc(sizeof(*s) * (i + 1))))
		return (0);
	i = 0;
	while (delta[i] && delta[i] != '\n')
	{
		s[i] = delta[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

static char	*ft_str_cut(char *delta)
{
	int		i;
	char	*ndelta;
	char	*freedelta;

	if (!delta)
		return (NULL);
	freedelta = delta;
	while (*delta && *delta != '\n')
		delta++;
	if (!(*delta) || !(ndelta = (char *)malloc(sizeof(*ndelta) *
					(ft_strlen(delta) + 1))))
	{
		free(freedelta);
		return (0);
	}
	delta++;
	i = -1;
	while (delta[++i])
		ndelta[i] = delta[i];
	ndelta[i] = '\0';
	if (freedelta)
		free(freedelta);
	return (ndelta);
}

int			get_next_line(int fd, char **line)
{
	int			ret;
	char		*buf;
	static char	*delta;

	ret = 1;
	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = (char *)malloc(sizeof(*buf) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!ft_str_hasreturn(delta) && ret != 0)
	{
		if ((ret = read(fd, buf, BUFFER_SIZE)) < 0)
			return (-1);
		buf[ret] = '\0';
		delta = ft_str_join(delta, buf);
	}
	free(buf);
	*line = ft_get_line(delta);
	delta = ft_str_cut(delta);
	if (ret == 0)
		return (0);
	return (1);
}
