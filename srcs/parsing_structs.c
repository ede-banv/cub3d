/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_structs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:05:37 by ede-banv          #+#    #+#             */
/*   Updated: 2020/02/03 19:41:50 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include "cub3d.h"


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

char    *skipspace(char **str, int r)
{
    while (**str == (r == 2 ? ' ' : '\n')) //if 2 skip space else skip \n
        (*str)++;
    return (*str);
}

void    ft_tri(char *res, t_pars *pars) //intialiser la structure pour faire erreurs de doublons
{
    skipspace(&res, 2);
    if (*res == 'R')
        ft_resolution(&res, pars);
    else if (*res == 'NO'|| *res == 'SO' || *res == 'WE' || *res == 'EA' || *res == 'S')
        ft_textures(&res, pars);
    else if (*res == 'F' || *res == 'C')
        ft_color(&res, pars);
}

t_pars  *parsing(t_pars *pars, char *res) //gestion d'erreurs et messages d'erreur. variable globale?
{
    int count;
    count = 0;
    while (count < 8)
    {
        skipspace(&res, 1);
        ft_tri(&res, pars);
    }
    skipspace(&res, 1);
    ft_map(&res, pars);
    return (pars);
}