/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restart.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:20:26 by ede-banv          #+#    #+#             */
/*   Updated: 2020/02/26 22:16:24 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/cub3d.h"
# define WinWidth 500
# define WinHeight 500
# define bloc 64

int     **map = {
{1, 1, 1, 1, 1},
{1, 0, 0, 0, 1},
{1, 0, 'N', 0, 1},
{1, 0, 0, 0, 1},
{1, 1, 1, 1, 1}}

void    raycasting(float rad, t_all *all)
{
    t_pos a;
    t_pos new;

    a.x = all->pos.x + tan(rad)
}

void    startprogramlol()
{
    t_all *all;
    float   rad;
    int     i;

    if (!(all = (t_all *)malloc(sizeof(t_all))))
        return (NULL);
    all->p.x = 2 + 0,5;
    all->p.y = 2 + 0,5;
    all->rot = -90;
    all->fov = 60;
    rad = -2,0944;
    i = 0;
    while (i < WinWidth)
    {

    }
}
//utiliser des double ou des float
//pour tracer une droite: