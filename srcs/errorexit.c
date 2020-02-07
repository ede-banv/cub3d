/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorexit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:05:18 by ede-banv          #+#    #+#             */
/*   Updated: 2020/02/07 16:15:26 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_putstr_fd(char *s, int fd)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}

void    ft_argerror(int n)
{
    if (n == 0)
        ft_putstr_fd("Too few aguments.\n", 2);
    else if (n == 1)
        ft_putstr_fd("Too many arguments.\n", 2);
    else if (n == 2)
        ft_putstr_fd("Incorrect file name.\n", 2);
    else if (n == 3)
        ft_putstr_fd("Incorrect second argument.\n", 2);
    else if (n == 4)
        ft_putstr_fd("Problem opening file.\n", 2);
    exit(EXIT_FAILURE);
}

void    ft_parsingerror(int n)
{
    if (n == 0)
        ft_putstr_fd("Please only define each element once.\n", 2);
    else if (n == 1)
        ft_putstr_fd("Resolution error.\n", 2);
    else if (n == 2)
        ft_putstr_fd("Texture path error.\n", 2);
    else if (n == 3)
        ft_putstr_fd("Floor color error.\n", 2);
    else if (n == 4)
        ft_putstr_fd("Ceiling color error.\n", 2);
    else if (n == 5)
        ft_putstr_fd("Map error: Please input a closed map.\n", 2);
    else if (n == 5)
        ft_putstr_fd("Map error: Please input a map with the correct elements.\n", 2);
    else if (n == 5)
        ft_putstr_fd("Map error: Please verify your map.\n", 2);
    exit(EXIT_FAILURE);
}

void    ft_othererror(int n)
{
    if (n == 0)
        ft_putstr_fd("Memory allocation error.\n", 2);
    else if (n == 1)
        ft_putstr_fd("Reading error.\n", 2);
    else if (n == 2)
        ft_putstr_fd("Image display Error.\n", 2);
    else if (n == 3)
        ft_putstr_fd("Image saving error.\n", 2);
    else if (n == 4)
        ft_putstr_fd("Mlx problem.\n", 2);
    exit(EXIT_FAILURE);
}

void    ft_exit(int n, int e)
{
    ft_putstr_fd("Error.\n", 2);
    if (n == 1)
        ft_argerror(e);
    else if (n == 2)
        ft_parsingerror(e);
    else
        ft_othererror(e);
}