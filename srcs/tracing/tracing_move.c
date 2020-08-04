/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 00:17:26 by ede-banv          #+#    #+#             */
/*   Updated: 2020/08/04 14:55:21 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_moveup_down(t_play *py, t_pars *pars, int n)
{
	if (n == 1) //up
	{

		if (pars->map[(int)(py->p.y + py->dir.y * py->speed)][(int)py->p.x] != 1)
			py->p.y += py->dir.y * py->speed;
		if (pars->map[(int)py->p.y][(int)(py->p.x + py->dir.x * py->speed)] != 1)
			py->p.x += py->dir.x * py->speed;
	}
	else if (n == 2) //down
	{
		if (pars->map[(int)py->p.y][(int)(py->p.x - py->dir.x * py->speed)] != 1)
			py->p.x -= py->dir.x * py->speed;
		if (pars->map[(int)(py->p.y - py->dir.y * py->speed)][(int)py->p.x] != 1)
			py->p.y -= py->dir.y * py->speed;
	}
}

void	ft_moveright_left(t_play *py, t_pars *pars, int n)
{
	if (n == 1) //right
	{
		if (pars->map[(int)(py->p.y + py->plane.y * py->speed)][(int)py->p.x] != 1)
			py->p.x += py->plane.x * py->speed;
		if (pars->map[(int)py->p.y][(int)(py->p.x + py->plane.x * py->speed)] != 1)
			py->p.y += py->plane.y * py->speed;
	}
	else if (n == 2) //left
	{
		if (pars->map[(int)py->p.y][(int)(py->p.x - py->plane.x * py->speed)] == 0)
			py->p.x -= py->plane.x * py->speed;
		if (pars->map[(int)(py->p.y - py->plane.y * py->speed)][(int)py->p.x] == 0)
			py->p.y -= py->plane.y * py->speed;
	}
}

void	ft_turn(t_play *py, int n)
{
	double	tmpdirx;
	double	tmpplnx;

	tmpdirx = py->dir.x;
	tmpplnx = py->plane.x;
	if (n == 2)
	{
		py->dir.x = tmpdirx * cos(-py->rotspeed) - py->dir.y * sin(-py->rotspeed);
		py->dir.y = tmpdirx * sin(-py->rotspeed) + py->dir.y * cos(-py->rotspeed);
		py->plane.x = tmpplnx * cos(-py->rotspeed) - py->plane.y * sin(-py->rotspeed);
		py->plane.y = tmpplnx * sin(-py->rotspeed) + py->plane.y * cos(-py->rotspeed);
	}
	else if (n == 1)
	{
		py->dir.x = tmpdirx * cos(py->rotspeed) - py->dir.y * sin(py->rotspeed);
		py->dir.y = tmpdirx * sin(py->rotspeed) + py->dir.y * cos(py->rotspeed);
		py->plane.x = tmpplnx * cos(py->rotspeed) - py->plane.y * sin(py->rotspeed);
		py->plane.y = tmpplnx * sin(py->rotspeed) + py->plane.y * cos(py->rotspeed);
	}
}