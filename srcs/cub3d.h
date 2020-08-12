/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:49:52 by ede-banv          #+#    #+#             */
/*   Updated: 2020/08/04 14:50:58 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*
//mac
//ARROW POUR TOURNER
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define EXIT_CODE 53
//WASD POUR BOUGER

# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define W_KEY 13


# define ESC_KEY 53
# define SHIFT_KEY 257 //speed button
# define SPACE_KEY 49

//LINUX not VM
# define ARROW_LEFT 65361
# define ARROW_RIGHT  65363

# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define W_KEY 119


# define ESC_KEY 65307
*/

//VM
# define W_KEY 119
# define A_KEY 97
# define D_KEY 100
# define S_KEY 115

# define ESC_KEY 65307
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define SHIFT_KEY 65505

//for res (a changer avec le get screen size)
# define MAXRES_X 2560
# define MAXRES_Y 1440
//speed
# define FOOT_STEP 0.09
# define FAST_STEP 0.15
# define ROT_SPEED 0.03
# define FAST_ROT 0.08

# define TEXWIDTH 64

# include "utils/utils.h"
# include "mlx.h"

/*
**actual meat
*/
void	startprogram(char *file, int n);

/*
**parsing
*/
void	parsing(t_all *all, int fd);
void	ft_tri(char *res, t_pars *pars, t_all *all);
int		ft_resolution(t_pars *pars, char **res, int *inst, t_all *all);
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
int	    ft_texturedraw(t_all *all, int i, int j);
void    ft_raycast(t_all *all);

/*
**sprites
*/
void	ft_locspr(t_all *all);
void	ft_sprites(t_all *all, t_sp *sp, int sp_nb);

/*
**keys and events
*/
int     ft_ispressed(int key, void *param);
int     ft_isdone(int key, void *param);
int     ft_iskill();
int     deal_key(void *param);
void    ft_init_keys(t_play *py);
void	ft_moveright_left(t_play *py, t_pars *pars, int n);
void	ft_moveup_down(t_play *py, t_pars *pars, int n);
void	ft_turn(t_play *py, int n);

/*
**error handling and freeing memory
*/
void	ft_exit(int n, int e);

#endif
