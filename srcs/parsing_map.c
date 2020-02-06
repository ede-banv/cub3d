/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 17:48:30 by ede-banv          #+#    #+#             */
/*   Updated: 2020/02/06 18:27:13 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include "cub3d.h"

int     ft_map(t_pars *pars, int **res, t_all *all)
{
    int i;

    i = 0;
    //on check s'il y a un \n\n, puis sinon on fait un split, puis on check chaque ligne
    if (ft_strnstr(*res, "\n\n", ft_strlen(*res)))
        return (-1);
    while ((*res)[i] == '1' || (*res)[i] == '2' || (*res)[i] == '0' || 
    ((*res)[i] == 'N' || (*res)[i] == 'W' || (*res)[i] == 'E' || (*res)[i] == 'S'))
        i++;
}