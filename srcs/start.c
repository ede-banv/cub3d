/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:06:49 by ede-banv          #+#    #+#             */
/*   Updated: 2020/08/26 11:33:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_checkline(char *data, char *pars)
{
	int	i;

	i = 0;
	while (data[i])
	{
		if (ft_strchr(pars, (int)data[i]))
			i++;
		else
			return (0);
	}
	if (i == 0)
		return (0);
	return (1);
}

void	ft_tri(char *res, t_pars *pars, t_all *all)
{
	static int	instances[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	printf("%s\n", res);
	skipspace(&res, 2);
	if (*res == 'R')
	{
		if (ft_resolution(pars, &res, instances, all) == -1)
			ft_exit(2, 1);
	}
	else if (*res == 'N' || *res == 'S' || *res == 'W' || *res == 'E')
	{
		if (ft_textures(pars, &res, instances, all) == -1)
			ft_exit(2, 2);
	}
	else if (*res == 'F' || *res == 'C')
	{
		if (ft_colors(pars, &res, instances) == -1)
			ft_exit(2, 3);
	}
	else if (ft_checkline(res, "1 ") || *res == '\n' || *res == '\0')
		return ;
	else
		ft_exit(1, 5);
}

int		ft_save(t_all *all)
{
	if (!(all->win.img.image = mlx_new_image(all->win.mlx_ptr,
	all->pars.res[0], all->pars.res[1])))
		ft_exit(3, 0);
	if (!(all->win.img.data = (int *)mlx_get_data_addr(all->win.img.image,
	&all->win.img.bpp, &all->win.img.size_l, &all->win.img.endian)))
		ft_exit(3, 0);
	if ((all->save.fd = open("screen.bmp", O_WRONLY | O_CREAT | O_TRUNC,
					S_IRWXU | S_IRGRP | S_IROTH)) < 0)
		ft_exit(3, 3);
	deal_key(all);
	if (ft_write_bmp(all, all->save.fd) < 1)
		ft_exit(3, 3);
	if ((write(all->save.fd, all->win.img.data, all->pars.res[0] *
	all->pars.res[1] * 4)) < 1)
		ft_exit(3, 3);
	close(all->save.fd);
	ft_end_save(all);
	exit(0);
}

void	parsing(t_all *all, int fd)
{
	char	*data;
	int		n;

	n = 1;
	while (n == 1)
	{
		n = get_next_line(fd, &data);
		ft_tri(data, &all->pars, all);
		if (ft_checkline(data, "1 "))
		{
			ft_map(all, fd, data);
			parsing_check(all);
			n = 0;
		}
		if (data)
		{
			free(data);
			data = NULL;
		}
	}
}

void	startprogram(char *file, int n)
{
	t_all	*all;
	int		fd;

	if (!(all = (t_all *)ft_memalloc(sizeof(t_all))))
		ft_exit(3, 0);
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_exit(1, 4);
	if (!(all->win.mlx_ptr = mlx_init()))
		ft_exit(3, 4);
	ft_init(all);
	parsing(all, fd);
	ft_init_text(all);
	close(fd);
	if (all->pars.map == NULL || all->pars.map[0] == NULL)
		ft_exit(2, 4);
	if (n == 2)
	{
		all->s = 1;
		ft_save(all);
	}
	else
		ft_graphic(all);
}
