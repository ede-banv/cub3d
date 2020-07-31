/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 16:08:33 by ede-banv          #+#    #+#             */
/*   Updated: 2020/07/31 16:13:58 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_locspr(t_all *all)
{
	int		i; //y
	int		j; //x
	int		sprite_count;

	i = 0;
	sprite_count = 0;
	while (all->pars.map[i])
	{
		j = 0;
		while (j < all->pars.w[i])
		{
			if (all->pars.map[i][j] == 2 && sprite_count < 50)
			{
				all->sp[sprite_count].x = j;
				all->sp[sprite_count++].y = i;
			}
			j++;
		}
		i++;
	}
}