/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:49:52 by ede-banv          #+#    #+#             */
/*   Updated: 2020/02/19 14:53:16 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "structures.h"
# include "utils/utils.h"

//error handling
void    ft_exit(int n, int e);

//parsing
void    parsing(t_all *all, int fd);
void    ft_tri(char *res, t_pars *pars, t_all *all);
int     ft_resolution(t_pars *pars, char **res, char *inst);
int     ft_textures(t_pars *pars, char **res, char *inst, t_all *all);
int     ft_textno(t_pars *pars, char **res, char *inst, t_all *all);
int     ft_textwe(t_pars *pars, char **res, char *inst, t_all *all);
int     ft_textea(t_pars *pars, char **res, char *inst, t_all *all);
int     ft_textsso(t_pars *pars, char **res, char *inst, t_all *all);
int     ft_color(char **res, t_pars *pars, char *inst);
int     ft_checkcolor(char **res);
int     checkcolorc(t_pars *pars, char **res, char *inst);
int     ft_checkline(char *data, char *pars);
void    ft_map(t_all *all, int fd, char *data);

#endif