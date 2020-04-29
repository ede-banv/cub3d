/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: softemma <softemma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 00:17:26 by ede-banv          #+#    #+#             */
/*   Updated: 2020/04/29 16:45:50 by softemma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_moveup_down(t_play *py, t_pars *pars, int n)
{
	if (n == 1) //up
	{

		if (pars->map[(int)(py->p.y + py->dir.y * FOOT_STEP)][(int)py->p.x] != 1)
			py->p.y += py->dir.y * FOOT_STEP;
		if (pars->map[(int)py->p.y][(int)(py->p.x + py->dir.x * FOOT_STEP)] != 1)
			py->p.x += py->dir.x * FOOT_STEP;
	}
	else if (n == 2) //down
	{
		if (pars->map[(int)py->p.y][(int)(py->p.x - py->dir.x * FOOT_STEP)] != 1)
			py->p.x -= py->dir.x * FOOT_STEP;
		if (pars->map[(int)(py->p.y - py->dir.y * FOOT_STEP)][(int)py->p.x] != 1)
			py->p.y -= py->dir.y * FOOT_STEP;
	}
}

void	ft_moveright_left(t_play *py, t_pars *pars, int n)
{
	if (n == 1) //right
	{
		if (pars->map[(int)(py->p.y + py->plane.y * FOOT_STEP)][(int)py->p.x] != 1)
			py->p.x += py->plane.x * FOOT_STEP;
		if (pars->map[(int)py->p.y][(int)(py->p.x + py->plane.x * FOOT_STEP)] != 1)
			py->p.y += py->plane.y * FOOT_STEP;
	}
	else if (n == 2) //left
	{
		if (pars->map[(int)py->p.y][(int)(py->p.x - py->plane.x * FOOT_STEP)] == 0)
			py->p.x -= py->plane.x * FOOT_STEP;
		if (pars->map[(int)(py->p.y - py->plane.y * FOOT_STEP)][(int)py->p.x] == 0)
			py->p.y -= py->plane.y * FOOT_STEP;
	}
}
/*
void	ft_moveleft(t_play *py, t_pars *pars)
{
	if (pars->map[(int)(py->p.x - py->plane.x * FOOT_STEP)][(int)py->p.y] == 0)
		py->p.x -= py->plane.x * FOOT_STEP;
	if (pars->map[(int)py->p.x][(int)(py->p.y - py->plane.y * FOOT_STEP)])
		py->p.y -= py->plane.y * FOOT_STEP;
}*/
void	ft_turn(t_play *py, int n)
{
	double	tmpdirx;
	double	tmpplnx;

	tmpdirx = py->dir.x;
	tmpplnx = py->plane.x;
	if (n == 2)
	{
		py->dir.x = tmpdirx * cos(-ROT_SPEED) - py->dir.y * sin(-ROT_SPEED);
		py->dir.y = tmpdirx * sin(-ROT_SPEED) + py->dir.y * cos(-ROT_SPEED);
		py->plane.x = tmpplnx * cos(-ROT_SPEED) - py->plane.y * sin(-ROT_SPEED);
		py->plane.y = tmpplnx * sin(-ROT_SPEED) + py->plane.y * cos(-ROT_SPEED);
	}
	else if (n == 1)
	{
		py->dir.x = tmpdirx * cos(ROT_SPEED) - py->dir.y * sin(ROT_SPEED);
		py->dir.y = tmpdirx * sin(ROT_SPEED) + py->dir.y * cos(ROT_SPEED);
		py->plane.x = tmpplnx * cos(ROT_SPEED) - py->plane.y * sin(ROT_SPEED);
		py->plane.y = tmpplnx * sin(ROT_SPEED) + py->plane.y * cos(ROT_SPEED);
	}
}