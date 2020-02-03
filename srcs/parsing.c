/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:29:05 by ede-banv          #+#    #+#             */
/*   Updated: 2020/02/03 17:51:53 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "structures.h"
#include "utils/utils.h"
//xpm to image man new_image pr les texture xdxdxdxd merci mli xdxdxd

int             ft_atoipositif(char **str)
{
    int n;
    int i;

    n = 0;
    i = 0;
    while (**str == ' ')
        (*str)++;
    if (**str == '-')
        return (-1);
    while (**str >= '0' && **str <= '9')
    {
        n = (n * 10) + (**str - 48);
        (*str)++;
    }
    if (i != 0)
        return (n);
    else
        return (-1);
}

char    *skipspace(char *str, int r)
{
    while (*str == (r == 2 ? ' ' : '\n')) //if 2 skip space else skip \n
        str++;
    return (str);
}

int     ft_freeer(char **res, t_pars *pars)
{
    if (res)
    {
        free(*res);
        *res = NULL;
    }
    return (pars);
}
//maybe make individual functions to check each parameter to make sure there are no value errors.
//make sure to have a function to check errors and show the correct error message.
//pars w gnl.

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

t_pars  *parsing(t_pars *pars, char *res)
{
    while (*res != 'R')
        res++;
    
}

t_pars  *ft_open(char *file)
{
    t_pars  *pars;
    char    *res;
    int     fd;

    if ((fd = open(file, O_RDONLY)) == -1)
        return (NULL);
    if (!(res = reading(fd)))
        return (ft_freeer(&res, NULL));
    if (!(pars = parsing(pars, res)))
        return (ft_freeer(&res, NULL));
    return (ft_freeer(&res, pars));
}
/*
int main(int ac, char **av)
{
    int fd;

    if (ac == 2)
    {
        fd = open(av[1], O_RDONLY);
        printf("%s", reading(fd));
    }
    return (0);
}
*/