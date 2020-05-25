/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:58:35 by ede-banv          #+#    #+#             */
/*   Updated: 2020/05/25 15:55:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//pour le tracing jai besoin d'un wallx
//wallx = posy + pwd * raydiry (if side <1, else x) (real distance of wall)
//textx 
//maybe change the draw vline function so for each direction instead of 
void	drawvline(t_all *all, int i)
{
	char *texture;//changer par un char * que je vais donner a ma fonction qui va dessiner la texture
	int		width;
	t_img	*img;
	int		j;

	j = 0;
	img = &all->win.img;
	width = all->pars.res[0];
	if (all->player.side == 1 && all->player.stepy == 1) //sud
		texture = all->pars.textadd.so; //assigner la bonne texture
	if (all->player.side == 1 && all->player.stepy == -1)//nord
		texture = all->pars.textadd.no;
	if (all->player.side == 0 && all->player.stepx == 1)//east
		texture = all->pars.textadd.ea;
	if (all->player.side == 0 && all->player.stepx == -1)//west
		texture = all->pars.textadd.we;
	while (j < img->dstart)
		img->data[j++ * width + i] = all->pars.c;
	texturedraw(all, i, texture);
	j = img->dend;
	while (j < all->pars.res[1])
		img->data[j++ * width + i] = all->pars.f;
}

//intialiser les structures avec get data address et les stocker qqpart (textaddr) (done)
//je dois le mettre avant le get data adrr de mon image (done)
void	ft_init_text(t_all *all)
{
	all->pars.textadd.no = mlx_get_data_addr(all->pars.texture.no,
			&all->win.img.bpp, &all->win.img.size_l, &all->win.img.endian);
	all->pars.textadd.so = mlx_get_data_addr(all->pars.texture.so,
			&all->win.img.bpp, &all->win.img.size_l, &all->win.img.endian);
	all->pars.textadd.ea = mlx_get_data_addr(all->pars.texture.ea,
			&all->win.img.bpp, &all->win.img.size_l, &all->win.img.endian);
	all->pars.textadd.we = mlx_get_data_addr(all->pars.texture.we,
			&all->win.img.bpp, &all->win.img.size_l, &all->win.img.endian);
	all->pars.textadd.sp = mlx_get_data_addr(all->pars.texture.sp,
			&all->win.img.bpp, &all->win.img.size_l, &all->win.img.endian);
}

void	texturedraw(t_all *all, int i, char *texture)
{
	double wallx;
	int textx;
	int texty;
	t_play *py;
	int		x;

	py = *all->player;
	x = all->win.img.dstart;
	if (py.side == 0)
		wallx = py.p.y + py.pwd * py.raydir.y;
	else
		wallx = py.p.x + py.pwd * py.raydir.x;
	textx = (int)(wallx * (double)TEXWIDTH);
	if (py.side == 0 && py.raydir.x > 0)
		textx = TEXWIDTH - textx - 1;
	if (py.side == 1 && py.raydir.y < 0)
		textx = TEXWIDTH - textx - 1;
	while (x < all->win.img.dend)
	{
		texty = abs((((x * 256 - all->pars.res[1] +
		all->win.img.lineh * 128) * 64) /
		all->win.img.lineh) / 256);
		ft_memcpy(all->win.img.data + 4 * all->parse.res[0] * x + 4 * i,
			&texture[texty % 64 *
			all->win.img.size_l + textx % 64 *
			all->win.img.bpp / 8], sizeof(int))
	}
	
	/*version de red1
	textx = TEXWIDTH - textx - 1;
	textx = abs(textx);
	*/
}
