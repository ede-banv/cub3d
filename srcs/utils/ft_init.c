/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 13:47:50 by user42            #+#    #+#             */
/*   Updated: 2020/08/18 14:04:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init(t_all *all)
{
	all->pars.sp = 0;
	all->s = 0;
	all->player.speed = FOOT_STEP;
	all->player.rotspeed = ROT_SPEED;
	ft_init_keys(&all->player);
	if (!(mlx_get_screen_size(all->win.mlx_ptr,
		&all->win.maxw, &all->win.maxh)))
		ft_exit(3, 0);
}

void	ft_init_tab(t_all *all)
{
	int	i;

	i = 0;
	while (i < 50)
	{
		all->sp[i].x = 0;
		all->sp[i].y = 0;
		i++;
	}
}

void	ft_init_text(t_all *all)
{
	if (!(all->pars.textadd.no = mlx_get_data_addr(all->pars.texture.no,
			&all->pars.texture.tbpp[0], &all->pars.texture.tsize_l[0],
			&all->pars.texture.tendian[0])))
		ft_exit(3, 0);
	if (!(all->pars.textadd.so = mlx_get_data_addr(all->pars.texture.so,
			&all->pars.texture.tbpp[1], &all->pars.texture.tsize_l[1],
			&all->pars.texture.tendian[1])))
		ft_exit(3, 0);
	if (!(all->pars.textadd.ea = mlx_get_data_addr(all->pars.texture.ea,
			&all->pars.texture.tbpp[2], &all->pars.texture.tsize_l[2],
			&all->pars.texture.tendian[2])))
		ft_exit(3, 0);
	if (!(all->pars.textadd.we = mlx_get_data_addr(all->pars.texture.we,
			&all->pars.texture.tbpp[3], &all->pars.texture.tsize_l[3],
			&all->pars.texture.tendian[3])))
		ft_exit(3, 0);
	if (!(all->pars.textadd.sp = mlx_get_data_addr(all->pars.texture.sp,
			&all->pars.texture.tbpp[4], &all->pars.texture.tsize_l[4],
			&all->pars.texture.tendian[4])))
		ft_exit(3, 0);
}

void	ft_init_keys(t_play *py)
{
	py->mov.up = 0;
	py->mov.down = 0;
	py->mov.left = 0;
	py->mov.right = 0;
	py->mov.turnl = 0;
	py->mov.turnr = 0;
	py->mov.close = 0;
	py->mov.speed = 0;
}
