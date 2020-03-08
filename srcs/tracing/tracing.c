/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 21:51:26 by ede-banv          #+#    #+#             */
/*   Updated: 2020/03/08 01:24:15 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	drawvline(t_all *all, int i)
{
	int 	color;
	int		width;
	t_img	img;
	int		j;

	j = 0;
	img = all->win.img;
	width = all->pars.res[0];
	if (all->player.side == 1 && all->player.step.y == 1) //sud
		color = 0xffD700;
	if (all->player.side == 1 && all->player.step.y == -1)//nord
		color = 0xff1493;
	if (all->player.side == 0 && all->player.step.x == 1)//east
		color = 0xffA500;
	if (all->player.side == 0 && all->player.step.y == 0)//west
		color = 0xff0000;
	img.image = mlx_new_image(all->win.mlx_ptr, width, all->pars.res[1]);
	img.data = (int *)mlx_get_data_addr(img.image, &img.bpp, &img.size_l, &img.endian);
	while (j < img.dstart)
		img.data[j++ * width + i] = all->pars.c;
	while (j < img.dend)
		img.data[j++ * width + i] = color;
	while (j < all->pars.res[1])
		img.data[j++ * width + i] = all->pars.f;
}

void test(t_all *all)
{
	t_play	py;
	int		i;
	double	time;
	double	oldtime;

	py = all->player;
	py.dir.x = -1;
	py.dir.y = 0;
	py.plane.x = 0;
	py.plane.y = 0.66;

	i = 0;
	time = 0;
	oldtime = 0;

	all->win.win_ptr = mlx_new_window(all->win.mlx_ptr, all->pars.res[0], all->pars.res[1], "name");
	while (i < all->pars.res[0])
	{
		ft_putchar_fd('c', 1);
		/*
		**cameraX shows which part of the plane we are i (coefficient)
		**raydir is the place where the ray interects with the plane (direction)
		*/
		double cameraX = 2 * i / (double)all->pars.res[0] - 1;
		py.raydir.x = py.dir.x + py.plane.x * cameraX;
		py.raydir.y = py.dir.y + py.plane.y * cameraX;
		/*
		**deltadist is the distance the ray has from one x(or y) coord to the next
		**map is the grid coordinate of the ray
		**hit is if there is a wall hit
		*/
	//check if raydirx/y are == 0
		py.deltadist.x = py.raydir.x < 0 ? 1 / py.raydir.x * -1 : 1 / py.raydir.x;
		py.deltadist.y = py.raydir.y < 0 ? 1 / py.raydir.y * -1 : 1 / py.raydir.y;
		py.mapx = (int)py.p.x;
		py.mapy = (int)py.p.y;
		py.hit = 0;
		/*
		**
		*/
		if (py.raydir.x < 0)
		{
			py.step.x = -1;
			py.sidedist.x = (py.p.x - py.mapx) * py.deltadist.x;
		}
		else
		{
			py.step.x = 1;
			py.sidedist.x = (py.mapx + 1.0 + py.p.x) * py.deltadist.x;
		}
		if (py.raydir.y < 0)
		{
			py.step.y = -1;
			py.sidedist.y = (py.p.y - py.mapy) * py.deltadist.y;
		}
		else
		{
			py.step.y = 1;
			py.sidedist.y = (py.mapy + 1.0 + py.p.y) * py.deltadist.y;
		}
		/*
		**DDA
		*/
		while (py.hit == 0)
		{
					ft_putchar_fd('d', 1);
			if (py.sidedist.x < py.sidedist.y)
			{
				py.sidedist.x += py.deltadist.x;
				py.mapx += py.step.x;
				py.side = 0;
			}
			else
			{
				py.sidedist.y += py.deltadist.y;
				py.mapy += py.step.y;
				py.side = 1;
			}
			ft_putnbr_fd(py.p.y, 1);
			if (all->pars.map[py.mapy][py.mapx] == 1)
				py.hit = 1;
					ft_putchar_fd('e', 1);
		}
				ft_putchar_fd('f', 1);
		/*
		**calculate wall distance
		*/
		if (py.side == 0)
			py.pwd = (py.mapx - py.p.x + (1 - py.step.x) / 2) / py.raydir.x;
		else
			py.pwd = (py.mapy - py.p.y + (1 - py.step.y) / 2) / py.raydir.y;
				ft_putchar_fd('g', 1);
		/*
		**calculate size to show on screen fr the wall
		*/
		all->win.img.lineh = (int)(all->pars.res[1] / py.pwd);
		all->win.img.dstart = -all->win.img.lineh / 2 + all->pars.res[1] / 2;
		if (all->win.img.dstart < 0)
			all->win.img.dstart = 0;
		all->win.img.dend = all->win.img.lineh / 2 + all->pars.res[1] / 2;
		if (all->win.img.dend < 0)
			all->win.img.dend = all->pars.res[1] - 1;

		drawvline(all, i);
	ft_putchar_fd('\n', 1);
		i++;
	}
	mlx_put_image_to_window(all->win.mlx_ptr, all->win.win_ptr, all->win.img.image, 0, 0);
	mlx_loop(all->win.mlx_ptr);
}
