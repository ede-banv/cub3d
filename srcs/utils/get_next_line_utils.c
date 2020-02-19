/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:27:53 by ede-banv          #+#    #+#             */
/*   Updated: 2020/02/19 19:45:07 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*tab;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen((char *)s2) + ft_strlen((char *)s1);
	if (!(tab = malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	while (s1[i])
		tab[j++] = s1[i++];
	i = 0;
	while (s2[i])
		tab[j++] = s2[i++];
	tab[j] = '\0';
	return (tab);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!s)
		return (NULL);
	if (!(res = malloc(sizeof(*res) * (len + 1))))
		return (NULL);
	if (start < (unsigned int)ft_strlen((char *)s))
	{
		while (i < len && s[start])
			res[i++] = s[start++];
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_noleak(char **stock, char **buf)
{
	char *tmp;

	if (!(tmp = ft_strjoin(*stock, *buf)))
		return (NULL);
	free(*stock);
	*stock = NULL;
	if (!(*stock = ft_substr(tmp, 0, ft_strlen(tmp))))
		return (NULL);
	free(tmp);
	tmp = NULL;
	return (*stock);
}
