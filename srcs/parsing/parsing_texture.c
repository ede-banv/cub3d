/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:29:08 by ede-banv          #+#    #+#             */
/*   Updated: 2020/08/17 15:50:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_textno(t_pars *pars, char **res, int *inst, t_all *all)
{
	(*res)++;
	if (**res != 'O')
		return (-1);
	(*res)++;
	skipspace(res, 2);
	if (!(pars->texture.no = mlx_xpm_file_to_image(all->win.mlx_ptr,
							*res, &all->win.width, &all->win.height)))
		return (-1);
	inst[1] += 1;
	if (inst[1] > 1)
		return (-1);
	return (1);
}

int		ft_textwe(t_pars *pars, char **res, int *inst, t_all *all)
{
	(*res)++;
	if (**res != 'E')
		return (-1);
	(*res)++;
	skipspace(res, 2);
	if (!(pars->texture.we = mlx_xpm_file_to_image(all->win.mlx_ptr, *res,
										&all->win.width, &all->win.height)))
		return (-1);
	inst[2] += 1;
	if (inst[2] > 1)
		return (-1);
	return (1);
}

int		ft_textea(t_pars *pars, char **res, int *inst, t_all *all)
{
	(*res)++;
	if (**res != 'A')
		return (-1);
	(*res)++;
	skipspace(res, 2);
	if (!(pars->texture.ea = mlx_xpm_file_to_image(all->win.mlx_ptr, *res,
										&all->win.width, &all->win.height)))
		return (-1);
	inst[3] += 1;
	if (inst[3] > 1)
		return (-1);
	return (1);
}

int		ft_textsso(t_pars *pars, char **res, int *inst, t_all *all)
{
	(*res)++;
	if (**res == 'O')
	{
		(*res)++;
		skipspace(res, 2);
		if (!(pars->texture.so = mlx_xpm_file_to_image(all->win.mlx_ptr,
								*res, &all->win.width, &all->win.height)))
			return (-1);
		inst[4] += 1;
		if (inst[4] > 1)
			return (-1);
	}
	else
	{
		if (skipspace(res, 2) && !(pars->texture.sp = mlx_xpm_file_to_image(
					all->win.mlx_ptr, *res, &all->win.width, &all->win.height)))
			return (-1);
		else
		{
			inst[5] += 1;
			if (inst[5] > 1)
				return (-1);
		}
	}
	return (1);
}

int		checkcolorc(t_pars *pars, char **res, int *inst)
{
	int		t;
	char	*tab;

	(*res)++;
	tab = (char *)&pars->c;
	if ((t = ft_checkcolor(res)) == -1)
		return (-1);
	tab[2] = t;
	if ((t = ft_checkcolor(res)) == -1)
		return (-1);
	tab[1] = t;
	if ((t = ft_checkcolor(res)) == -1)
		return (-1);
	tab[0] = t;
	inst[7] += 1;
	if (inst[7] > 1)
		return (-1);
	return (1);
}
