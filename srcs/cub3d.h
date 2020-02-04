/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:07:40 by ede-banv          #+#    #+#             */
/*   Updated: 2020/02/04 14:09:42 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "structures.h"

t_pars  *ft_open(char *file);
t_pars  *parsing(t_pars *pars, char *res);
int     ft_tri(char *res, t_pars *pars);
int     ft_resolution(t_pars *pars, char **res, char **inst);
int     ft_textures(t_pars *pars, char **res, char **inst);
int     ft_color(t_pars *pars, char **res, char **inst);
#endif