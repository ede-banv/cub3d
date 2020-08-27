/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:06:26 by ede-banv          #+#    #+#             */
/*   Updated: 2020/08/27 12:11:11 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		skippath(char **res)
{
	while (**res > 32 && **res <= 126)
		(*res)++;
	skipspace(res, 2);
	if (**res != '\0' && **res != '\n')
		return (-1);
	return (1);
}

int		ft_resolution(t_pars *pars, char **res, int *inst, t_all *all)
{
	int	t;

	(*res)++;
	inst[0] += 1;
	if (inst[0] > 1)
		return (-1);
	pars->res[0] = all->win.maxw;
	pars->res[1] = all->win.maxh;
	if ((t = ft_atoipositif(res)) == -1)
		return (-1);
	if (t == 0)
		return (-1);
	else if (t <= all->win.maxw)
		pars->res[0] = t;
	t = 0;
	if ((t = ft_atoipositif(res)) == -1)
		return (-1);
	if (t == 0)
		return (-1);
	else if (t <= all->win.maxh)
		pars->res[1] = t;
	skipspace(res, 2);
	return ((**res == '\n' || **res == '\0') ? 1 : -1);
}

int		ft_textures(t_pars *pars, char **res, int *inst, t_all *all)
{
	if (**res == 'N')
	{
		if (ft_textno(pars, res, inst, all) == -1)
			return (-1);
	}
	else if (**res == 'W')
	{
		if (ft_textwe(pars, res, inst, all) == -1)
			return (-1);
	}
	else if (**res == 'E')
	{
		if (ft_textea(pars, res, inst, all) == -1)
			return (-1);
	}
	else if (**res == 'S')
	{
		if (ft_textsso(pars, res, inst, all) == -1)
			return (-1);
	}
	if (skippath(res) == -1)
		return (-1);
	return (1);
}
