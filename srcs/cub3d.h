/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:49:52 by ede-banv          #+#    #+#             */
/*   Updated: 2020/07/29 18:22:43 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//mac
//ARROW POUR TOURNER
# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define EXIT_CODE 53
//WASD POUR BOUGER

# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define W_KEY 13


# define ESC_KEY 53
/*
//LINUX
# define ARROW_LEFT 65361
# define ARROW_RIGHT  65363

# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define W_KEY 119


# define ESC_KEY 65307
*/
# define SHIFT_KEY 257
# define C_KEY 8
# define R_KEY 15
# define P_KEY 35
# define SPACE_KEY 49
# define M_KEY 46
# define L_KEY 37
# define I_KEY 34
# define O_KEY 31
//for res
# define MAXRES_X 2560
# define MAXRES_Y 1440
//speed
# define FOOT_STEP 0.05
# define BIG_FOOT 1.8
# define ROT_SPEED 0.01

# define TEXWIDTH 64

# include "utils/utils.h"
# include "mlx.h"

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

/*
**fonctions d'affichage et de graphique
*/
void 	ft_graphic(t_all *all);
void	ft_drawvline(t_all *all, int i);
void    ft_init_text(t_all *all);
int	    ft_texturedraw(t_all *all, int i);
void    ft_raycast(t_all *all);
int     ft_ispressed(int key, void *param);
int     ft_isdone(int key, void *param);
int     ft_iskill();
int     deal_key(void *param);
void    ft_init_keys(t_play *py);
void	ft_moveright_left(t_play *py, t_pars *pars, int n);
void	ft_moveup_down(t_play *py, t_pars *pars, int n);
void	ft_turn(t_play *py, int n);

#endif
