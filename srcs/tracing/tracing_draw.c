/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: softemma <softemma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:58:35 by ede-banv          #+#    #+#             */
/*   Updated: 2020/04/27 20:20:52 by softemma         ###   ########.fr       */
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
	if (all->player.side == 1 && all->player.stepx == 1) //sud
		color = 0xffD700;
	if (all->player.side == 1 && all->player.stepy == -1)//nord
		color = 0xff1493;
	if (all->player.side == 0 && all->player.stepx == 1)//east
		color = 0xffA500;
	if (all->player.side == 0 && all->player.stepx == -1)//west
		color = 0xff0000;
	while (j < img->dstart)
		img->data[j++ * width + i] = all->pars.c;
	while (j < img->dend)
		img->data[j++ * width + i] = color;
	while (j < all->pars.res[1])

		img->data[j++ * width + i] = all->pars.f;
}

