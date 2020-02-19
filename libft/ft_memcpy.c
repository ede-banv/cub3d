/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:37:33 by ede-banv          #+#    #+#             */
/*   Updated: 2019/10/24 18:30:56 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;

	i = 0;
	if (!n || dst == src)
		return (dst);
	while (i < n)
	{
		*(char *)dst = *(char *)src;
		dst++;
		src++;
		i++;
	}
	return (dst - i);
}
