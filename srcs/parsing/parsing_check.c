/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 11:33:32 by ede-banv          #+#    #+#             */
/*   Updated: 2020/08/18 12:22:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_elements(t_all *all)
{
	t_pars	pars;

	pars = all->pars;
	if (pars.f == 0 || pars.c == 0)
		return (-1);
	if (pars.res[0] == 0 || pars.res[1] == 0)
		return (-1);
	if (pars.texture.no == NULL || pars.texture.so == NULL ||
	pars.texture.ea == NULL || pars.texture.we == NULL ||
	pars.texture.sp == NULL)
		return (-1);
	return (1);
}

int		ft_checksquare(t_pars pars)
{
	int	i;

	i = 0;
	while (pars.map[i])
	{
		if (i >= 1)
			if (pars.w[i] != pars.w[i - 1])
				return (0);
		i++;
	}
	return (1);
}

int		ft_nonsquare_end(int **map, int *w, int *i)
{
	int	j;

	if (w[*i] > w[*i - 1])
	{
		j = w[*i - 1];
		while (j < w[*i])
		{
			if (map[*i][j] != 1)
				return (-1);
			j++;
		}
	}
	else if (w[*i] < w[*i - 1])
	{
		j = w[*i];
		while (j < w[*i - 1])
		{
			if (map[*i - 1][j] != 1)
				return (-1);
			j++;
		}
	}
	return (1);
}

int		ft_nonsquare(t_pars *pars)
{
	int	**map;
	int	*w;
	int	i;

	i = 0;
	map = pars->map;
	w = pars->w;
	while (map[i])
	{
		if (i >= 1)
		{
			if (ft_nonsquare_end(map, w, &i) == -1)
				return (-1);
		}
		i++;
	}
	if (!lastline(pars))
		return (-1);
	return (1);
}

void	parsing_check(t_all *all)
{
	if (check_elements(all) == -1)
		ft_exit(2, 8);
	if (!ft_checksquare(all->pars))
	{
		if (ft_nonsquare(&all->pars) == -1)
			ft_exit(2, 4);
	}
	if (ft_position(all) == -1)
		ft_exit(2, 9);
	return ;
}
