/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing_spites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 16:29:57 by ede-banv          #+#    #+#             */
/*   Updated: 2020/07/31 16:37:46 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_sptxt(t_all *all, t_spt *sptxt)
{
	int i;
	int j;
	int pixel;

	i = sptxt->draw_sx;
	while (i < sptxt->draw_ex)
	{
		sptxt->textx = (int)((256 * (i - (-sptxt->spr_w / 2
		+ sptxt->screen_x)) * TEXWIDTH / sptxt->spr_w) / 256);
		j = sptxt->draw_sy;
		while (j < sptxt->draw_ey && sptxt->transform_y > 0 &&
				sptxt->transform_y < all->zbuff[i])
		{
			sptxt->d = j * 256 - all->pars.res[1] * 128 + sptxt->spr_h
			* 128;
			sptxt->texty = ((sptxt->d * TEXWIDTH) / sptxt->spr_h) / 256;
			ft_memcpy(&pixel,
					&all->pars.textadd.sp[sptxt->texty % 64 * all->pars.texture.tsize_l[4]
					+ sptxt->textx % 64 * all->pars.texture.tbpp[4] / 8], sizeof(int));
			if (pixel != 0 && pixel != -16777216 && pixel != 9961608)
					ft_memcpy(&all->win.img.data[j * all->pars.res[0] + i],
					&pixel, sizeof(int));
			j++;
		}
		i++;
	}
}

void	ft_calc_sp(t_all *all, t_spt *sptxt, t_sp *sp, int *sp_order)
{
	sptxt->x = sp[sp_order[sptxt->i]].x - all->player.p.x;
	sptxt->y = sp[sp_order[sptxt->i]].y - all->player.p.y;
	sptxt->inv_det = 1.0 / (all->player.plane.x * all->player.dir.y
	- all->player.dir.x * all->player.plane.y);
	sptxt->transform_x = sptxt->inv_det * (all->player.dir.y * sptxt->x
	- all->player.dir.x * sptxt->y);
	sptxt->transform_y = sptxt->inv_det * (-all->player.plane.y * sptxt->x
	+ all->player.plane.x * sptxt->y);
	sptxt->screen_x = (int)((all->pars.res[0] / 2) *
	(1 + sptxt->transform_x / sptxt->transform_y));
	sptxt->spr_h = abs((int)(all->pars.res[1] / sptxt->transform_y));
	sptxt->draw_sy = -sptxt->spr_h / 2 + all->pars.res[1] / 2;
	if (sptxt->draw_sy < 0)
		sptxt->draw_sy = 0;
	sptxt->draw_ey = sptxt->spr_h / 2 + all->pars.res[1] / 2;
	if (sptxt->draw_ey >= all->pars.res[1])
		sptxt->draw_ey = all->pars.res[1] - 1;
	sptxt->spr_w = abs((int)(all->pars.res[1] / sptxt->transform_y));
	sptxt->draw_sx = -sptxt->spr_w / 2 + sptxt->screen_x;
	if (sptxt->draw_sx < 0)
		sptxt->draw_sx = 0;
	sptxt->draw_ex = sptxt->spr_w / 2 + sptxt->screen_x;
	if (sptxt->draw_ex >= all->pars.res[0])
		sptxt->draw_ex = all->pars.res[0] - 1;
}

void	ft_check_sp_dist(int sp, int *sp_order, double *sp_dist)
{
	int		i;
	int		tmp_ordr;
	double	tmp_dist;

	i = 0;
	while (i < sp - 1)
	{
		if (sp_dist[i] > sp_dist[i + 1])
		{
			tmp_dist = sp_dist[i + 1];
			sp_dist[i + 1] = sp_dist[i];
			sp_dist[i] = tmp_dist;
			tmp_ordr = sp_order[i + 1];
			sp_order[i + 1] = sp_order[i];
			sp_order[i] = tmp_ordr;
			i = 0;
		}
		else
			i++;
	}
}

void	ft_init_sp(t_all *all, t_sp *sp, double *sp_dist, int *sp_order)
{
	int i;

	i = 0;
	while (i < all->pars.sp)
	{
		sp_dist[i] = ((all->player.p.x - sp[i].x) *
		(all->player.p.x - sp[i].x) + (all->player.p.y - sp[i].y)
		* (all->player.p.y - sp[i].y));
		sp_order[i] = i;
		i++;
	}
	ft_check_sp_dist(all->pars.sp, sp_order, sp_dist);
}

void	ft_sprites(t_all *all, t_sp *sp, int sp_nb)
{
	int			sp_order[sp_nb];
	double		sp_dist[sp_nb];
	t_spt		sptxt;

	ft_init_sp(all, sp, sp_dist, sp_order);
	sptxt.i = sp_nb - 1;
	while (sptxt.i >= 0)
	{
		ft_calc_sp(all, &sptxt, sp, sp_order);
		ft_sptxt(all, &sptxt);
		sptxt.i--;
	}
	mlx_put_image_to_window(all->win.mlx_ptr, all->win.win_ptr, all->win.img.image, 0, 0);
}