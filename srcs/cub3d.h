/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:49:52 by ede-banv          #+#    #+#             */
/*   Updated: 2020/03/09 19:14:34 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "utils/utils.h"
# include "../minilibx_opengl_20191021/mlx.h"

/*
**error handling and exiting lol
*/
void	ft_exit(int n, int e);

/*
**actual meat
*/
void	startprogram(char *file, int n);

/*
**parsing
*/
void	parsing(t_all *all, int fd);
void	ft_tri(char *res, t_pars *pars, t_all *all);
int		ft_resolution(t_pars *pars, char **res, int *inst);
int		ft_textures(t_pars *pars, char **res, int *inst, t_all *all);
int		ft_textno(t_pars *pars, char **res, int *inst, t_all *all);
int		ft_textwe(t_pars *pars, char **res, int *inst, t_all *all);
int		ft_textea(t_pars *pars, char **res, int *inst, t_all *all);
int		ft_textsso(t_pars *pars, char **res, int *inst, t_all *all);
int		ft_colors(t_pars *pars, char **res, int *inst);
int		ft_checkcolor(char **res);
int		checkcolorc(t_pars *pars, char **res, int *inst);
int		ft_checkline(char *data, char *pars);
void	ft_map(t_all *all, int fd, char *data);
void	parsing_check(t_all *all);
int		ft_position(t_all *all);
int		lastline(t_pars *pars);
void 	test(t_all *all, int s);

#endif
