/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 16:08:33 by ede-banv          #+#    #+#             */
/*   Updated: 2020/08/18 13:52:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_locspr(t_all *all)
{
	int		y;
	int		x;
	int		sprite_count;

	y = 0;
	sprite_count = 0;
	while (all->pars.map[y])
	{
		x = 0;
		while (x < all->pars.w[y])
		{
			if (all->pars.map[y][x] == 2 && sprite_count < 50)
			{
				all->sp[sprite_count].x = x + 0.5;
				all->sp[sprite_count++].y = y + 0.5;
			}
			x++;
		}
		y++;
	}
}
