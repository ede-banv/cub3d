/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:06:49 by ede-banv          #+#    #+#             */
/*   Updated: 2020/02/07 16:28:26 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    startprogram(char *file, int n)
{
    t_all   *all;
    int     fd;

    if ((fd = open(file, O_RDONLY)) == -1)
        ft_exit(1, 4);
    if (!(all->win.mlx_ptr = mlx_init()))
        ft_exit(3, 4);
    parsing(all);
    //this should return a fully malloqued & filled pars structure OR just exit by itself.
    //as well as the player info partially filled.
    //so next to do:
    // create a window & image if n == 1 save
    // do calculs lol

}