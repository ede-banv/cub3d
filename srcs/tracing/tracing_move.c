/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 00:17:26 by ede-banv          #+#    #+#             */
/*   Updated: 2020/08/17 15:41:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_compare(int n)
{
	if (n == 1 || n == 2)
		return (0);
	return (1);
}

void	ft_moveup_down(t_play *py, t_pars *pars, int n)
{
	if (n == 1) //up
	{

		if (ft_compare(pars->map[(int)(py->p.y + py->dir.y * py->speed)][(int)py->p.x]))
			py->p.y += py->dir.y * py->speed;
		if (ft_compare(pars->map[(int)py->p.y][(int)(py->p.x + py->dir.x * py->speed)]))
			py->p.x += py->dir.x * py->speed;
	}
	else if (n == 2) //down
	{
		if (ft_compare(pars->map[(int)py->p.y][(int)(py->p.x - py->dir.x * py->speed)]))
			py->p.x -= py->dir.x * py->speed;
		if (ft_compare(pars->map[(int)(py->p.y - py->dir.y * py->speed)][(int)py->p.x]))
			py->p.y -= py->dir.y * py->speed;
	}
}

void	ft_moveright_left(t_play *py, t_pars *pars, int n)
{
	if (n == 1) //right
	{
		if (ft_compare(pars->map[(int)(py->p.y + py->plane.y * py->speed)][(int)py->p.x]))
			py->p.y += py->plane.y * py->speed;
		if (ft_compare(pars->map[(int)py->p.y][(int)(py->p.x + py->plane.x * py->speed)]))
			py->p.x += py->plane.x * py->speed;
	}
	else if (n == 2) //left
	{
		if (ft_compare(pars->map[(int)py->p.y][(int)(py->p.x - py->plane.x * py->speed)]))
			py->p.x -= py->plane.x * py->speed;
		if (ft_compare(pars->map[(int)(py->p.y - py->plane.y * py->speed)][(int)py->p.x]))
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