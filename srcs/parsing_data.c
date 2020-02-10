/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:06:26 by ede-banv          #+#    #+#             */
/*   Updated: 2020/02/10 20:58:17 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int    skippath(char **res)
{
    while (**res >= 32 && **res <= 126)
    {
        if (**res == 32)
        {
            if (**(res - 1) != 92)
                return (-1);
        }
        (*res)++;
    }
    return(1);
}

int     ft_resolution(t_pars *pars, char **res, char *inst)
{
    int t;

    (*res)++;
    inst[0] += 1;
    if (inst[0] > 1)
        return (-1);
    pars->res[0] = MAXRES_X;
    pars->res[1] = MAXRES_Y;
    if ((t = ft_atoipositif(res)) == -1)
        return (-1);
    if (t == 0)
        return (-1);
    else if (t <= MAXRES_X)
        pars->res[0] = t;
    t = 0;
    if ((t = ft_atoipositif(res)) == -1)
        return (-1);
    if (t == 0)
        return (-1);
    else if (t <= MAXRES_Y)
        pars->res[1] = t;
    return (1);
}

int     ft_textures(t_pars *pars, char **res, char *inst, t_all *all)
{
    if (**res == 'N') //tt ca cest faux
    {
        if (ft_textno(pars, res, inst, all) == -1)
            return (-1);
    }
    else if ((*res)++ == 'W')
    {
        if (ft_textwe(pars, res, inst, all) == -1)
            return (-1);
    }
    else if ((*res)++ == 'E')
    {
        if (ft_textea(pars, res, inst, all) == -1)
            return (-1);
    }
    else if ((*res)++ == 'S')
    {
        if (ft_textsso(pars, res, inst, all) == -1)
            return (-1);
    }
    if (skippath(res) == -1)
        return (-1);
    return (1);
}

int     ft_checkcolor(char **res)
{
    int t;
    
    (*res)++;
    if ((t = ft_atoipositif(res)) == -1)
        return (-1);
    else if (t >= 0 && t <= 255)
        return (t);
    else
        return (-1);
}

int     ft_colors(t_pars *pars, char **res, char *inst)
{
    int     t;
    char    *tab;

    if (**res == 'F')
    {
        tab = (char *)&pars->f;
        if (t == ft_checkcolor(res) == -1)
            return (-1);
        tab[0] = t;
        if (t == ft_checkcolor(res) == -1)
            return (-1);
        tab[1] = t;
        if (t == ft_checkcolor(res) == -1)
            return (-1);
        tab[2] = t;
        inst[6] += 1;
        if (inst[6] > 1)
            return (-1);
    }
    else if (**res == 'C')
        if (checkcolorc(pars, res, inst) == -1)
            return (-1);
    return (1);
}
