/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:05:31 by ede-banv          #+#    #+#             */
/*   Updated: 2020/02/06 17:48:12 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int		count_wrds(char const *s, char c)
{
	int in_wrd;
	int i;
	int len;

	in_wrd = 0;
	i = 0;
	len = 0;
	if (!s)
		return ((int)NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			if (in_wrd != 1)
				len++;
			in_wrd = 1;
		}
		else
			in_wrd = 0;
		i++;
	}
	return (len);
}

static int		wrd_len(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char		**ft_free(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i]);
	free(tab);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		len;
	char	**res;

	i = 0;
	len = count_wrds(s, c);
	if (!(res = malloc(sizeof(res) * (len + 1))) || !s)
		return (NULL);
	while (*s && i < len)
	{
		if (*s == c)
			s++;
		else
		{
			if (!(res[i] = malloc(sizeof(res[i]) * (wrd_len(s, c) + 1))))
				return (ft_free(res));
			ft_strlcpy(res[i++], s, wrd_len(s, c) + 1);
			while (*s != c && *s)
				s++;
		}
	}
	res[len] = NULL;
	return (res);
}
