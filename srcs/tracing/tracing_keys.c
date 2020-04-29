/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: softemma <softemma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 20:33:18 by softemma          #+#    #+#             */
/*   Updated: 2020/04/29 16:54:20 by softemma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_ispressed(int key, void *param)
{
	t_all *all;

	all = (t_all *)param;
	if (key == W_KEY)
		all->player.mov.up = 1;
	if (key == S_KEY)
		all->player.mov.down = 1;
	if (key == A_KEY)
		all->player.mov.left = 1;
	if (key == D_KEY)
		all->player.mov.right = 1;
	if (key == ARROW_LEFT)
		all->player.mov.turnl = 1;
	if (key == ARROW_RIGHT)
		all->player.mov.turnr = 1;
	if (key == ESC_KEY)
		all->player.mov.close = 1;
	return (0);
}

int		ft_isdone(int key, void *param)
{
	t_all *all;

	all = (t_all *)param;
	if (key == W_KEY)
		all->player.mov.up = 0;
	if (key == S_KEY)
		all->player.mov.down = 0;
	if (key == A_KEY)
		all->player.mov.left = 0;
	if (key == D_KEY)
		all->player.mov.right = 0;
	if (key == ARROW_LEFT)
		all->player.mov.turnl = 0;
	if (key == ARROW_RIGHT)
		all->player.mov.turnr = 0;
	if (key == ESC_KEY)
		all->player.mov.close = 0;
	return (0);
}

int		ft_iskill(void *param)
{
	t_all *all;
	all = (t_all *)param;
	mlx_clear_window(all->win.mlx_ptr, all->win.win_ptr);
	mlx_destroy_window(all->win.mlx_ptr, all->win.win_ptr);
	exit(0);
	return (0);
}

int		deal_key(void *param)
{
	t_all *all;

	all = (t_all *)param;
//	ft_putstr_fd("here\n", 1);
	if (all->player.mov.up == 1)
		ft_moveup_down(&all->player, &all->pars, 1);
	if (all->player.mov.down == 1)
		ft_moveup_down(&all->player, &all->pars, 2);
	if (all->player.mov.left == 1)
		ft_moveright_left(&all->player, &all->pars, 2);
	if (all->player.mov.right == 1)
		ft_moveright_left(&all->player, &all->pars, 1);
	if (all->player.mov.turnl == 1)
		ft_turn(&all->player, 2);
	if (all->player.mov.turnr)
		ft_turn(&all->player, 1);
	if (all->player.mov.close == 1)
		exit(0);
	ft_raycast(all);
	return(1);
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
}