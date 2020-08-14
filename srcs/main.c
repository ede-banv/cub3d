/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:53:33 by ede-banv          #+#    #+#             */
/*   Updated: 2020/08/14 15:17:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		checkfile(char *file)
{
	int		len;
	int		i;
	int		j;
	char	*cub;

	if (!file)
		return (-1);
	len = ft_strlen(file);
	i = len - 5;
	j = 0;
	cub = ".cub";
	while (i < len)
	{
		if (file[i++] == cub[j])
			j++;
	}
	if (j == 4)
		return (1);
	else
		return (-1);
}

int		checksave(char *save)
{
	char	*arg;
	int		i;

	i = 0;
	arg = "--save";
	if (!save)
		return (-1);
	while (save[i] == arg[i])
	{
		if (i == 5)
			return (1);
		i++;
	}
	return (-1);
}

int		main(int ac, char **av)
{
	if (ac < 2)
		ft_exit(1, 0);
	else if (ac > 3)
		ft_exit(1, 1);
	else if (ac == 2)
	{
		if (checkfile(av[1]) == -1)
			ft_exit(1, 2);
		startprogram(av[1], 1);
	}
	else if (ac == 3)
	{
		if (checkfile(av[1]) == -1)
			ft_exit(1, 2);
		if (checksave(av[2]) == -1)
			ft_exit(1, 3);
		startprogram(av[1], 2);
	}
	return (0);
}
