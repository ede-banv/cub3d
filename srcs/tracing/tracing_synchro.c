/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing_synchro.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:19:04 by user42            #+#    #+#             */
/*   Updated: 2020/08/26 18:27:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_pixel(t_all *all, int *image, t_vec pos)
{
	char	*tab;
	int		color;

	tab = (char *)&color;
	tab[0] = 255;
	tab[1] = 255;
	tab[2] = 255;
	image[(int)pos.y * all->pars.res[0] + (int)pos.x] = color;
}

void	clear_application(t_all *all)
{
	t_vec	pos;

	pos.x = 0;
	pos.y = 0;
	if (!(mlx_do_sync(all->win.mlx_ptr)))
		ft_exit(3, 0);
	while (pos.x < (size_t)all->pars.res[0])
	{
		pos.y = 0;
		while (pos.y < (size_t)all->pars.res[1])
		{
			put_pixel(all, all->win.img.data, pos);
			pos.y++;
		}
		pos.x++;
	}
}
