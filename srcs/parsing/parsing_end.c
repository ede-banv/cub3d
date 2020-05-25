/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:52:49 by ede-banv          #+#    #+#             */
/*   Updated: 2020/05/19 15:18:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		lastline(t_pars *pars)
{
	int i;
	int j;
	int **map;

	i = 0;
	j = 0;
	map = pars->map;
	while (map[i])
		i++;
	i--;
	while (j < pars->w[i])
	{
		if (map[i][j] != 1)
			return (0);
		j++;
	}
	return (1);
}

void	ft_assign(t_all *all, double dirx, double diry, double planex, double planey)
{
	all->player.dir.x = dirx;
	all->player.dir.y = diry;
	all->player.plane.x = planex;
	all->player.plane.y = planey;
}

int		ft_joueur(t_all *all, int *count, char c)
{
	if (c == 'N')
		ft_assign(all, 0, -1, 0.66, 0);
	else if (c == 'S')
		ft_assign(all, 0, 1, -0.66, 0);
	else if (c == 'W')
		ft_assign(all, -1, 0, 0, -0.66);
	else if (c == 'E')
		ft_assign(all, 1, 0, 0, 0.66);
	if (*count == 0)
		(*count)++;
	return (*count == 1 ? 1 : -1);
}

int		ft_position(t_all *all)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (all->pars.map[i])
	{
		j = 0;
		while (j < all->pars.w[i])
		{
			if (all->pars.map[i][j] == 'N' || all->pars.map[i][j] == 'S' ||
			all->pars.map[i][j] == 'E' || all->pars.map[i][j] == 'W')
			{
				all->player.p.x = j + 0.5;
				all->player.p.y = i + 0.5;
				if (ft_joueur(all, &count, all->pars.map[i][j]) == -1)
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (count == 0 ? -1 : 1);
}
