/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_structs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:05:37 by ede-banv          #+#    #+#             */
/*   Updated: 2020/02/06 17:27:14 by ede-banv         ###   ########.fr       */
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
    while (**str >= '0' && **str <= '9' && i++)
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

void    ft_exit(int n)
{
    ft_putstr("Error\n");
    if (n == 1)
        ft_putstr("Please check that the data in your .cub file is valid.");
    if (n == 2)
        ft_putstr("Map Error: Please check that your map is valid.");
    exit(EXIT_FAILURE);
}
//resolution doit pas apsser la taille de l'ordi donc si plus grand definir a la taille de l'ordi
//textures: checker rendu de xpm to image pr  erreur
//verifier valeurs

int    ft_tri(char *res, t_pars *pars, t_all *all) //intialiser la structure pour faire erreurs de doublons
{
    char    instances[8];
    int i;

    i = 0;
    while (i++ < 8)
        instances[i] = 0;
    skipspace(&res, 2);
    if (*res == 'R')
    {
        if (ft_resolution(&res, pars, instances) == -1)
            return (-1);
    }
    else if (*res == 'N'|| *res == 'S' || *res == 'W' || *res == 'E') //possibilite d'erreur
    {
        if (ft_textures(&res, pars, instances, all) == -1)
            return (-1);
    }
    else if (*res == 'F' || *res == 'C')
    {
        if (ft_color(&res, pars, instances) == -1)
            return (-1);
    }
    else
        return (-1);
    skipspace(res, 2); 
    return (1);
}

t_pars  *parsing(t_pars *pars, char *res, t_all *all) //gestion d'erreurs et messages d'erreur. variable globale?
{
    int count;

    count = 0;
    while (count < 8)
    {
        skipspace(&res, 1);
        if (ft_tri(&res, pars, all) == -1)
            ft_exit(1);
    }
    skipspace(&res, 1);
    if(ft_map(&res, pars) == -1) //strchr  pr savoir s'il y a un \n
        ft_exit(2);
    return (pars);
}
