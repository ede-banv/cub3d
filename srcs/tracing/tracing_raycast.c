/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing_raycast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 13:28:40 by user42            #+#    #+#             */
/*   Updated: 2020/08/18 13:29:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init_raycast(t_all *all, int i)
{
	t_play	*py;
	double	camerax;

	py = &all->player;
	camerax = 2 * i / (double)all->pars.res[0] - 1;
	py->raydir.x = py->dir.x + py->plane.x * camerax;
	py->raydir.y = py->dir.y + py->plane.y * camerax;
}

void	ft_startrc(t_all *all)
{
	t_play *py;

	py = &all->player;
	py->mapx = (int)py->p.x;
	py->mapy = (int)py->p.y;
	if (py->raydir.y == 0)
		py->deltadist.x = 0;
	else if (py->raydir.x == 0)
		py->deltadist.x = 1;
	else
		py->deltadist.x = fabs(1 / py->raydir.x);
	if (py->raydir.x == 0)
		py->deltadist.y = 0;
	else if (py->raydir.y == 0)
		py->deltadist.y = 1;
	else
		py->deltadist.y = fabs(1 / py->raydir.y);
	py->hit = 0;
}

void	ft_firstraydir(t_all *all)
{
	t_play *py;

	py = &all->player;
	if (py->raydir.x < 0)
	{
		py->stepx = -1;
		py->sidedist.x = (py->p.x - py->mapx) * py->deltadist.x;
	}
	else
	{
		py->stepx = 1;
		py->sidedist.x = (py->mapx + 1.0 - py->p.x) * py->deltadist.x;
	}
	if (py->raydir.y < 0)
	{
		py->stepy = -1;
		py->sidedist.y = (py->p.y - py->mapy) * py->deltadist.y;
	}
	else
	{
		py->stepy = 1;
		py->sidedist.y = (py->mapy + 1.0 - py->p.y) * py->deltadist.y;
	}
}

void	ft_dda(t_all *all)
{
	t_play *py;

	py = &all->player;
	while (py->hit == 0)
	{
		if (py->sidedist.x < py->sidedist.y)
		{
			py->sidedist.x += py->deltadist.x;
			py->mapx += py->stepx;
			py->side = 0;
		}
		else
		{
			py->sidedist.y += py->deltadist.y;
			py->mapy += py->stepy;
			py->side = 1;
		}
		if (all->pars.map[py->mapy][py->mapx] == 1)
			py->hit = 1;
	}
}

void	ft_wallcalc(t_all *all, int i)
{
	t_play *py;

	py = &all->player;
	if (py->side == 0)
		py->pwd = (py->mapx - py->p.x + (1 - py->stepx) / 2) / py->raydir.x;
	else
		py->pwd = (py->mapy - py->p.y + (1 - py->stepy) / 2) / py->raydir.y;
	all->zbuff[i] = py->pwd;
	all->win.img.lineh = (int)(all->pars.res[1] / py->pwd);
	all->win.img.dstart = -all->win.img.lineh / 2 + all->pars.res[1] / 2;
	if (all->win.img.dstart < 0)
		all->win.img.dstart = 0;
	all->win.img.dend = all->win.img.lineh / 2 + all->pars.res[1] / 2;
	if (all->win.img.dend >= all->pars.res[1])
		all->win.img.dend = all->pars.res[1] - 1;
	ft_drawvline(all, i);
}
