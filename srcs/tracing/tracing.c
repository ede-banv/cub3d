/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 21:51:26 by ede-banv          #+#    #+#             */
/*   Updated: 2020/08/18 13:29:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_raycast(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->pars.res[0])
	{
		ft_init_raycast(all, i);
		ft_startrc(all);
		ft_firstraydir(all);
		ft_dda(all);
		ft_wallcalc(all, i);
		i++;
	}
}

void	ft_graphic(t_all *all)
{
	if (!(all->win.win_ptr = mlx_new_window(all->win.mlx_ptr, all->pars.res[0],
	all->pars.res[1], "cub3D")))
		ft_exit(3, 0);
	if (!(all->win.img.image = mlx_new_image(all->win.mlx_ptr, all->pars.res[0],
	all->pars.res[1])))
		ft_exit(3, 0);
	if (!(all->win.img.data = (int *)mlx_get_data_addr(all->win.img.image,
	&all->win.img.bpp, &all->win.img.size_l, &all->win.img.endian)))
		ft_exit(3, 0);
	if (!(mlx_hook(all->win.win_ptr, 2, 1, ft_ispressed, all)))
		ft_exit(3, 0);
	if (!(mlx_hook(all->win.win_ptr, 3, 2, ft_isdone, all)))
		ft_exit(3, 0);
	if (!(mlx_hook(all->win.win_ptr, 17, 1L << 17, ft_iskill, all)))
		ft_exit(3, 0);
	if (!(mlx_loop_hook(all->win.mlx_ptr, deal_key, all)))
		ft_exit(3, 0);
	if (!(mlx_loop(all->win.mlx_ptr)))
		ft_exit(3, 0);
}
