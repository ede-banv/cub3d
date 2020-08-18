/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 15:27:48 by user42            #+#    #+#             */
/*   Updated: 2020/08/18 15:34:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_bmp_file_header(t_all *all, int fd, unsigned int wr)
{
	int ret;

	ret = 0;
	ret |= write(fd, &wr, 2);
	wr = all->pars.res[0] * all->pars.res[1] * 4 + 14 + 40;
	ret |= write(fd, &wr, 4);
	wr = 0;
	ret |= write(fd, &wr, 4);
	wr = 14 + 40;
	ret |= write(fd, &wr, 4);
	return (ret);
}

static int	ft_bmp_info_header(t_all *all, int fd, unsigned int wr)
{
	int ret;

	ret = 0;
	ret |= write(fd, &wr, 4);
	wr = all->pars.res[0];
	ret |= write(fd, &wr, 4);
	wr = (unsigned int)-all->pars.res[1];
	ret |= write(fd, &wr, 4);
	wr = 1;
	ret |= write(fd, &wr, 2);
	wr = 32;
	ret |= write(fd, &wr, 2);
	wr = 0;
	ret |= write(fd, &wr, 4);
	ret |= write(fd, &wr, 4);
	ret |= write(fd, &wr, 4);
	ret |= write(fd, &wr, 4);
	ret |= write(fd, &wr, 4);
	ret |= write(fd, &wr, 4);
	return (ret);
}

int			ft_write_bmp(t_all *all, int fd)
{
	int ret;

	ret = 0;
	ret |= ft_bmp_file_header(all, fd, 0x4d42);
	ret |= ft_bmp_info_header(all, fd, 40);
	return (ret);
}

void		ft_free_map(t_all *all)
{
	int i;

	i = 0;
	while (all->pars.map[i])
	{
		free(all->pars.map[i]);
		all->pars.map[i] = NULL;
		i++;
	}
	free(all->pars.map);
	free(all->pars.w);
}

void		ft_end_save(t_all *all)
{
	if (!(mlx_destroy_image(all->win.mlx_ptr, all->win.img.image)))
		ft_exit(3, 0);
	if (!(mlx_destroy_image(all->win.mlx_ptr, all->pars.texture.no)))
		ft_exit(3, 0);
	if (!(mlx_destroy_image(all->win.mlx_ptr, all->pars.texture.so)))
		ft_exit(3, 0);
	if (!(mlx_destroy_image(all->win.mlx_ptr, all->pars.texture.we)))
		ft_exit(3, 0);
	if (!(mlx_destroy_image(all->win.mlx_ptr, all->pars.texture.ea)))
		ft_exit(3, 0);
	if (!(mlx_destroy_image(all->win.mlx_ptr, all->pars.texture.sp)))
		ft_exit(3, 0);
	all->pars.textadd.no = NULL;
	all->pars.textadd.so = NULL;
	all->pars.textadd.we = NULL;
	all->pars.textadd.ea = NULL;
	all->pars.textadd.sp = NULL;
	free(all->win.mlx_ptr);
	all->win.mlx_ptr = NULL;
	ft_free_map(all);
	free(all);
}
