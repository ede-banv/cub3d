/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 21:20:28 by ede-banv          #+#    #+#             */
/*   Updated: 2020/02/19 20:17:36 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int     newlen(char *str)
{
    int i;

    i = 0;
    while (*str)
    {
        if (*str == '1' || *str == '0' || *str == '2' || *str == 'N' || *str == 'S' || *str == 'E' || *str == 'N')
            i++;
        str++;
    }
    return (i);
}

char    *ft_cleanline(char *str, int len)
{
    char    *final;
    int     i;

    i = 0;
    if (!(final = malloc(sizeof(char) * (len + 1))))
        return (NULL);
    while (*str)
    {
        if (*str == '1' || *str == '0' || *str == '2' || *str == 'N' || *str == 'S' || *str == 'E' || *str == 'N')
        {
            final[i] = *str;
            i++;
        }
        str++;
    }
    return (final);
}

void    ft_map(t_all *all, int fd, char *data)
{
    t_list  *alst;
    t_list  *lst;
    char    *tmp;
    int     r;
    int     n = 0;
    int     len;

    r = 1;
    n = 0;
    (void)all;
    while (r == 1)
    {
        if (n == 1)
            r = get_next_line(fd, &data);
        if (ft_checkline(data, " 012NSWE"))
            len = newlen(data);
        else
            ft_free(data, 2, 5);
        if (len == 0)
            ft_free(data, 2, 6);
        if (!(tmp = ft_cleanline(data, len)))
            ft_free(data, 3, 0);
        if (n != 1)
        {
            n++;
            alst = ft_lstnew(tmp);
        }
        else
        {
            lst = ft_lstnew(tmp);
            ft_lstadd_back(&alst, lst);
            free(lst);
        }
        free(data);
        free(tmp);
    }

}