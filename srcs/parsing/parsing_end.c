/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:52:49 by ede-banv          #+#    #+#             */
/*   Updated: 2020/08/18 16:30:14 by user42           ###   ########.fr       */
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

void	ft_assign(t_all *all, double x, double y, int n)
{
	if (n == 2)
	{
		all->player.dir.x = 0;
		all->player.dir.y = y;
		all->player.plane.x = x;
		all->player.plane.y = 0;
	}
	else
	{
		all->player.dir.x = x;
		all->player.dir.y = 0;
		all->player.plane.x = 0;
		all->player.plane.y = y;
	}
}

int		ft_joueur(t_all *all, int *count, char c)
{
	if (c == 'N')
		ft_assign(all, 0.66, -1, 2);
	else if (c == 'S')
		ft_assign(all, -0.66, 1, 2);
	else if (c == 'W')
		ft_assign(all, -1, -0.66, 3);
	else if (c == 'E')
		ft_assign(all, 1, 0.66, 3);
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
	return (count == 1 ? 1 : -1);
}
