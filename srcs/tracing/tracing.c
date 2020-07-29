/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 21:51:26 by ede-banv          #+#    #+#             */
/*   Updated: 2020/07/29 19:17:34 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init(t_all *all, int i)
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
/*
**calculate wall distance
*/
	if (py->side == 0)
		py->pwd = (py->mapx - py->p.x + (1 - py->stepx) / 2) / py->raydir.x;
	else
		py->pwd = (py->mapy - py->p.y + (1 - py->stepy) / 2) / py->raydir.y;
/*
**calculate size to show on screen fr the wall
*/
	all->win.img.lineh = (int)(all->pars.res[1] / py->pwd);
	all->win.img.dstart = -all->win.img.lineh / 2 + all->pars.res[1] / 2;
	if (all->win.img.dstart < 0)
		all->win.img.dstart = 0;
	all->win.img.dend = all->win.img.lineh / 2 + all->pars.res[1] / 2;
	if (all->win.img.dend >= all->pars.res[1])
		all->win.img.dend = all->pars.res[1] - 1;
	ft_drawvline(all, i);
}

void	ft_raycast(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->pars.res[0])
	{
		ft_init(all, i);
		ft_startrc(all);
		ft_firstraydir(all);
		ft_dda(all);
		ft_wallcalc(all, i);
		i++;
	}
	mlx_put_image_to_window(all->win.mlx_ptr, all->win.win_ptr, all->win.img.image, 0, 0);
}

void	ft_graphic(t_all *all)
{
	if (!(all->win.win_ptr = mlx_new_window(all->win.mlx_ptr, all->pars.res[0], all->pars.res[1], "cub3D")))
		ft_exit(3, 0);
	if (!(all->win.img.image = mlx_new_image(all->win.mlx_ptr, all->pars.res[0], all->pars.res[1])))
		ft_exit(3, 0);
	if (!(all->win.img.data = (int *)mlx_get_data_addr(all->win.img.image, &all->win.img.bpp, &all->win.img.size_l, &all->win.img.endian)))
		ft_exit(3, 0);
//	while (1)
//	{
		mlx_hook(all->win.win_ptr, 2, 1L<<0, ft_ispressed, all);
		mlx_hook(all->win.win_ptr, 3, 1L<<1, ft_isdone, all);
		mlx_hook(all->win.win_ptr, 17, 1L<<17, ft_iskill, all);
		mlx_loop_hook(all->win.mlx_ptr, deal_key, all); //fct qui va bouger et raycaster
		mlx_loop(all->win.mlx_ptr);
//	}
}
