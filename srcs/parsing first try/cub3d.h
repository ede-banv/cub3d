/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:07:40 by ede-banv          #+#    #+#             */
/*   Updated: 2020/02/07 14:49:12 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "structures.h"

t_pars  *ft_open(char *file, t_all *all);
t_pars  *parsing(t_pars *pars, char *res, t_all *all);
int     ft_tri(char *res, t_pars *pars, t_all *all);
int     ft_resolution(t_pars *pars, char **res, char *inst);
int     ft_textures(t_pars *pars, char **res, char *inst, t_all *all);
int     ft_textno(t_pars *pars, char **res, char *inst, t_all *all);
int     ft_textwe(t_pars *pars, char **res, char *inst, t_all *all);
int     ft_textea(t_pars *pars, char **res, char *inst, t_all *all);
int     ft_textsso(t_pars *pars, char **res, char *inst, t_all *all);
int     ft_color(t_pars *pars, char **res, char *inst);
int     ft_checkcolor(char **res);
int     checkcolorc(t_pars *pars, char *res, char *inst);

#endif