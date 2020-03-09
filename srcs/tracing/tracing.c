/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 21:51:26 by ede-banv          #+#    #+#             */
/*   Updated: 2020/03/09 23:06:11 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	drawvline(t_all *all, int i)
{
	int 	color;
	int		width;
	t_img	*img;
	int		j;

	j = 0;
	img = &all->win.img;
	width = all->pars.res[0];
	if (all->player.side == 1 && all->player.stepy == 1) //sud
		color = 0xffD700;
	if (all->player.side == 1 && all->player.stepy == -1)//nord
		color = 0xff1493;
	if (all->player.side == 0 && all->player.stepx == 1)//east
		color = 0xffA500;
	if (all->player.side == 0 && all->player.stepy == 0)//west
		color = 0xff0000;
	while (j < img->dstart)
		img->data[j++ * width + i] = all->pars.c;
	while (j < img->dend)
		img->data[j++ * width + i] = color;
	while (j < all->pars.res[1])

		img->data[j++ * width + i] = all->pars.f;
}

void	ft_init(t_all *all, int mode, int i)
{
	t_play	*py;
	double	camerax;

	py = &all->player;
	if (mode == 1)
	{
		all->player.plane.x = 0.66;
		all->player.plane.y = 0;
	}
	else if (mode == 2)
	{
		camerax = 2 * i / (double)all->pars.res[0] - 1;
		py->raydir.x = py->dir.x + py->plane.x * camerax;
		py->raydir.y = py->dir.y + py->plane.y * camerax;
	}
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
		py->deltadist.x = py->raydir.x < 0 ? (1 / py->raydir.x) * -1 : 1 / py->raydir.x;
	if (py->raydir.x == 0)
		py->deltadist.y = 0;
	else if (py->raydir.y == 0)
		py->deltadist.y = 1;
	else
		py->deltadist.y = py->raydir.y < 0 ? 1 / py->raydir.y * -1 : 1 / py->raydir.y;
	py->hit = 0;
}

void	ft_firstraydir(t_all *all)
{
	t_play *py;

	py = &all->player;
//	printf("raydirx:%f\traydiry:%f\n", py->raydir.x, py->raydir.y);
	if (py->raydir.x < 0)
	{
		py->stepx = -1;
		py->sidedist.x = (py->p.x - py->mapx) * py->deltadist.x;
	}
	else
	{
		py->stepx = 1;
		py->sidedist.x = (py->mapx + 1.0 + py->p.x) * py->deltadist.x;
	}
	if (py->raydir.y < 0)
	{
		py->stepy = -1;
		py->sidedist.y = (py->p.y - py->mapy) * py->deltadist.y;
	}
	else
	{
		py->stepy = 1;
		py->sidedist.y = (py->mapy + 1.0 + py->p.y) * py->deltadist.y;
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
	printf("%d\t%d : %d\n", py->mapx, py->mapy, py->hit);
	all->win.img.dstart = -all->win.img.lineh / 2 + all->pars.res[1] / 2;
	if (all->win.img.dstart < 0)
		all->win.img.dstart = 0;
	all->win.img.dend = all->win.img.lineh / 2 + all->pars.res[1] / 2;
	if (all->win.img.dend >= all->pars.res[1])
		all->win.img.dend = all->pars.res[1] - 1;
	drawvline(all, i);
}

void test(t_all *all, int s)
{
	int		i;
	double	time;
	double	oldtime;

	i = 0;
	time = 0;
	oldtime = 0;
	(void)s;
	ft_init(all, 1, 0);
	all->win.win_ptr = mlx_new_window(all->win.mlx_ptr, all->pars.res[0], all->pars.res[1], "cub3D");
	all->win.img.image = mlx_new_image(all->win.mlx_ptr, all->pars.res[0], all->pars.res[1]);
	all->win.img.data = (int *)mlx_get_data_addr(all->win.img.image, &all->win.img.bpp, &all->win.img.size_l, &all->win.img.endian);
	while (i < all->pars.res[0])
	{
		ft_init(all, 2, i);
		ft_startrc(all);
		ft_firstraydir(all);
		ft_dda(all);
		ft_wallcalc(all, i);
		i++;
	}
	mlx_put_image_to_window(all->win.mlx_ptr, all->win.win_ptr, all->win.img.image, 0, 0);
	mlx_loop(all->win.mlx_ptr);
}
