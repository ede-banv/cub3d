/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 00:17:26 by ede-banv          #+#    #+#             */
/*   Updated: 2020/08/18 14:02:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_compare(int n)
{
	if (n == 1 || n == 2)
		return (0);
	return (1);
}

void	ft_moveup_down(t_play *py, int **map, int n)
{
	if (n == 1)
	{
		if (ft_compare(map[(int)(py->p.y + py->dir.y * py->speed)]
		[(int)py->p.x]))
			py->p.y += py->dir.y * py->speed;
		if (ft_compare(map[(int)py->p.y]
		[(int)(py->p.x + py->dir.x * py->speed)]))
			py->p.x += py->dir.x * py->speed;
	}
	else if (n == 2)
	{
		if (ft_compare(map[(int)py->p.y]
		[(int)(py->p.x - py->dir.x * py->speed)]))
			py->p.x -= py->dir.x * py->speed;
		if (ft_compare(map[(int)(py->p.y - py->dir.y * py->speed)]
		[(int)py->p.x]))
			py->p.y -= py->dir.y * py->speed;
	}
}

void	ft_moveright_left(t_play *py, int **map, int n)
{
	if (n == 1)
	{
		if (ft_compare(map[(int)(py->p.y + py->plane.y * py->speed)]
		[(int)py->p.x]))
			py->p.y += py->plane.y * py->speed;
		if (ft_compare(map[(int)py->p.y]
		[(int)(py->p.x + py->plane.x * py->speed)]))
			py->p.x += py->plane.x * py->speed;
	}
	else if (n == 2)
	{
		if (ft_compare(map[(int)py->p.y]
		[(int)(py->p.x - py->plane.x * py->speed)]))
			py->p.x -= py->plane.x * py->speed;
		if (ft_compare(map[(int)(py->p.y - py->plane.y * py->speed)]
		[(int)py->p.x]))
			py->p.y -= py->plane.y * py->speed;
	}
}

void	ft_turn(t_play *py, int n)
{
	double	tmpdx;
	double	tmppx;

	tmpdx = py->dir.x;
	tmppx = py->plane.x;
	if (n == 2)
	{
		py->dir.x = tmpdx * cos(-py->rotspeed) - py->dir.y * sin(-py->rotspeed);
		py->dir.y = tmpdx * sin(-py->rotspeed) + py->dir.y * cos(-py->rotspeed);
		py->plane.x = tmppx * cos(-py->rotspeed) - py->plane.y *
		sin(-py->rotspeed);
		py->plane.y = tmppx * sin(-py->rotspeed) + py->plane.y *
		cos(-py->rotspeed);
	}
	else if (n == 1)
	{
		py->dir.x = tmpdx * cos(py->rotspeed) - py->dir.y * sin(py->rotspeed);
		py->dir.y = tmpdx * sin(py->rotspeed) + py->dir.y * cos(py->rotspeed);
		py->plane.x = tmppx * cos(py->rotspeed) - py->plane.y *
		sin(py->rotspeed);
		py->plane.y = tmppx * sin(py->rotspeed) + py->plane.y *
		cos(py->rotspeed);
	}
}
