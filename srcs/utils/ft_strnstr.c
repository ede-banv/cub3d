/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:39:52 by ede-banv          #+#    #+#             */
/*   Updated: 2020/02/06 17:48:22 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	int		a;
	int		size;

	i = 0;
	a = 0;
	size = 0;
	while (to_find[size])
		size++;
	while (str[i] && i < n)
	{
		if (str[i] == to_find[a])
			a++;
		else if (a == size)
			return (i - a + (char *)str);
		else if (a != 0)
		{
			a = 0;
			i--;
		}
		i++;
	}
	if (a == size)
		return (i - a + (char *)str);
	return (0);
}
