/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:06:26 by ede-banv          #+#    #+#             */
/*   Updated: 2020/02/04 15:23:59 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include "cub3d.h"

int     ft_resolution(t_pars *pars, char **res, char **inst)
{
    int t;

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

int     ft_textures(t_pars *pars, char **res, char **inst)
{
    
}

int     ft_colors(t_pars *pars, char **res, char **inst)
{
    
}