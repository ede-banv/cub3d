/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:52:49 by ede-banv          #+#    #+#             */
/*   Updated: 2020/03/09 17:14:12 by ede-banv         ###   ########.fr       */
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

int		ft_joueur(t_all *all, int *count, char c)
{
	if (c == 'N')
	{
		all->player.dir.x = 0;
		all->player.dir.y = -1;
	}
	else if (c == 'S')
	{
		all->player.dir.x = 0;
		all->player.dir.y = 1;
	}
	else if (c == 'W')
	{
		all->player.dir.x = -1;
		all->player.dir.y = 0;
	}
	else if (c == 'E')
	{
		all->player.dir.x = 1;
		all->player.dir.y = 0;
	}
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
