/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 15:04:17 by user42            #+#    #+#             */
/*   Updated: 2020/08/18 15:29:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_commas(t_pars *pars, char **res)
{
	int i;
	int	comma;

	i = 0;
	comma = 2;
	while (*res[i])
	{
		if (*res[i] == ',')
			comma--;
		else if ((ft_isdigit(*res[i]) == 0 && *res[i] != ','
		&& *res[i] != ' ') || comma < 0)
			return (-1);
		i++;
	}
	return (0);
}

int		ft_checkcolor(char **res)
{
	int	t;

	skipspace(res, 2);
	if (**res == ',')
		*res++;
	if ((t = ft_atoipositif(res)) == -1)
		return (-1);
	else if (t >= 0 && t <= 255)
		return (t);
	else
		return (-1);
}

int		checkcolor_end(int c, int j, int *inst)
{
	if (j == -1)
		inst[c == 1 ? 7 : 6] += 1;
	else
		return (-1);
	if (inst[c == 1 ? 7 : 6] > 1)
		return (-1);
	return (1);
}

int		ft_colors(t_pars *pars, char **res, int *inst)
{
	int		t;
	char	*tab;
	int		j;
	int		c;

	j = 2;
	c = 0;
	if (!check_commas(pars, res))
		return (-1);
	if (**res == 'F' || (**res == 'C' && (c = 1)))
	{
		tab = c == 1 ? (char *)&pars->c : (char *)&pars->f;
		while (j >= 0)
		{
			if ((t = ft_checkcolor(res)) == -1)
				return (-1);
			tab[j--] = t;
			skipspace(res, 2);
			if (j == -1 && (**res != ' ' && **res != '\0'))
				return (-1);
		}
	}
	return (checkcolor_end(c, j, inst) == -1 ? -1 : 1);
}
