/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoipositif.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:36:28 by ede-banv          #+#    #+#             */
/*   Updated: 2020/02/28 20:25:05 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_atoipositif(char **str)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (**str == ' ')
		(*str)++;
	if (**str == '-')
		return (-1);
	while (**str >= '0' && **str <= '9' && ++i)
	{
		n = (n * 10) + (**str - 48);
		(*str)++;
	}
	if (i != 0)
		return (n);
	else
		return (-1);
}

char	*skipspace(char **str, int r)
{
	while (**str == (r == 2 ? ' ' : '\n'))
		(*str)++;
	return (*str);
}
