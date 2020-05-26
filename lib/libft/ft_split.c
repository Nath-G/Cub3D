/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:58:52 by nagresel          #+#    #+#             */
/*   Updated: 2020/05/05 16:45:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char *s, char c)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		j = 0;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i + j] && s[i + j] != c)
				j++;
			i = i + j;
		}
		else
			i++;
	}
	return (count);
}

static char	*ft_str_create(char *s, char c)
{
	int		slen;
	char	*str;

	slen = 0;
	while (s[slen] && s[slen] != c)
		slen++;
	if (!(str = (char *)malloc(sizeof(*str) * (slen + 1))))
		return (NULL);
	str[0] = 0;
	return (str);
}

static char	*ft_filltab(char *s, char c)
{
	int		i;
	char	*word;

	if ((word = ft_str_create(s, c)) == NULL)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	ft_fill(char const *s, char c, char **stab, int wordnb)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (s[i] && k < wordnb)
	{
		j = 0;
		while ((char)s[i + 1] && (char)s[i] == c)
			i++;
		while ((char)s[i + j + 1] && (char)s[i] != c && (char)s[i + j] != c)
			j++;
		if ((stab[k++] = ft_filltab((char *)(s + i), c)) == NULL)
		{
			i = 0;
			while (stab[i] && i < k)
				free(stab[i++]);
			free(stab);
			return (0);
		}
		i = i + j;
	}
	stab[k] = 0;
	return (1);
}

char		**ft_split(char const *s, char c)
{
	int		wordnb;
	char	**stab;

	if (!s)
		return (NULL);
	wordnb = ft_countwords((char *)s, c);
	if (!(stab = (char **)malloc(sizeof(*stab) * (wordnb + 1))))
		return (0);
	if (ft_fill(s, c, stab, wordnb) == 0)
		return (NULL);
	if (stab == NULL)
		return (NULL);
	return (stab);
}
