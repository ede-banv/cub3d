/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:29:05 by ede-banv          #+#    #+#             */
/*   Updated: 2020/02/06 17:27:47 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include "cub3d.h"

int     ft_freeer(char **res, t_pars *pars)
{
    if (res)
    {
        free(*res);
        *res = NULL;
    }
    return (pars);
}

char    *restocklol(char **res, char *autre, int n)
{
    char *tmp;

    if (n == -1 || !(tmp = ft_strjoin(*res, "\n")))
        return (NULL);
    free(*res);
    *res = NULL;
    if (!(*res = ft_strjoin(tmp, autre)))
        return (NULL);
    free (tmp);
    tmp = NULL;
    return (*res);
}

char    *reading(int fd)
{
    char    *data;
    char    *res;
    int     n;

    n = 1;
    if (!(res = malloc(sizeof(char *) * 1)))
        return (NULL);
    res[0] = '\0';
    while (n == 1)
    {
        n = get_next_line(fd, &data);
        res = restocklol(&res, data, n);
        free(data);
        data = NULL;
        if (res == NULL)
            return (NULL);
    }
    return (res);
}

int     checkfile(char *file)
{
    int     len;
    int     i;
    int     j;
    char    cub[4];

    if (!file)
        return (-1);
    len = ft_strlen(file);
    i = len - 5;
    j = 0;
    *cub = ".cub";
    while (i < len)
    {
        if (file[i++] == cub[j])
            j++;
    }
    if (j == 4)
        return (1);
    else
        return (-1);
}

t_pars  *ft_open(char *file, t_all *all)
{
    t_pars  *pars;
    char    *res;
    int     fd;

    if (checkfile(file) == -1)
        return (NULL);
    if ((fd = open(file, O_RDONLY)) == -1)
        return (NULL);
    if (!(res = reading(fd)))
        return (ft_freeer(&res, NULL));
    if (!(pars = parsing(pars, res, all)))
        return (ft_freeer(&res, NULL));
    return (ft_freeer(&res, pars));
}
