/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 16:08:33 by ede-banv          #+#    #+#             */
/*   Updated: 2020/08/03 16:13:17 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init_tab(t_all *all)
{
	int	i;
	i = 0;
	while (i < 50)
	{
		all->sp[i].x = 0;
		all->sp[i].y = 0;
		i++;
	}
}

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
				all->sp[sprite_count].x = j + 0.5;
				all->sp[sprite_count++].y = i + 0.5;
			}
			j++;
		}
		i++;
	}
}
