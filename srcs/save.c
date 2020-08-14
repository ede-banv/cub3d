/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 15:27:48 by user42            #+#    #+#             */
/*   Updated: 2020/08/14 16:23:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     ft_init_save(t_save *save, t_all *all)
{
    save->size = 54 + 4 * all->pars.res[0] * all->pars.res[1];
    save->unused = 0;
    save->offset_begin = 54;
    save->header_bytes = 40;
    save->plane = 1;
    save->bpp = 32;
    save->fd = open("save.bmp", O_RDWR | O_CREAT, S_IRWXU | O_TRUNC);
    if (save->fd == -1)
        ft_exit(3, 3);//save error message
    return (1);
}

void    ft_write_bmp_text(t_all *all, int fd)
{
    int x;
    int y;
    int line;

    y = 0;
    while (y < all->pars.res[1])
    {
        x = 0;
        line = all->pars.res[0] * (all->pars.res[0] - y);
        while (x < all->pars.res[0])
        {
            write(fd, &all->win.img.data[line * 4], 4);
            line++;
            x++;
        }
        y++;
    }
}

void    ft_write_bmp(t_all *all)
{
    t_save *save;

    save = &all->save;
    ft_init_save(save, all);
    write(save->fd, "BM", 2);
    write(save->fd, &save->size, sizeof(int));
    write(save->fd, &save->unused, sizeof(int));
    write(save->fd, &save->offset_begin, sizeof(int));
    write(save->fd, &save->header_bytes, sizeof(int));
    write(save->fd, &all->pars.res[0], sizeof(int));
    write(save->fd, &all->pars.res[1], sizeof(int));
    write(save->fd, &save->plane, sizeof(int));
    write(save->fd, &save->bpp, sizeof(int));
    write(save->fd, &save->unused, sizeof(int));
    write(save->fd, &save->unused, sizeof(int));
    write(save->fd, &save->unused, sizeof(int));
    write(save->fd, &save->unused, sizeof(int));
    write(save->fd, &save->unused, sizeof(int));
    write(save->fd, &save->unused, sizeof(int));
    ft_write_bmp_text(all, save->fd);
    close(save->fd);
}

int     ft_save(t_all *all)
{
    deal_key(all);
    ft_write_bmp(all);
    //free map
    exit(0);
}