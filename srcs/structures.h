/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 19:54:24 by ede-banv          #+#    #+#             */
/*   Updated: 2020/02/28 20:46:10 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# define MAXRES_X 2560
# define MAXRES_Y 1440

# define WALL_HEIGHT
# define VIEW_HEIGHT

/*
**map structures
*/
typedef struct	s_txtr
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*sp;
}				t_txtr;

typedef struct	s_pars
{
	int		res[2];
	t_txtr	texture;
	int		f;
	int		c;
	int		**map;
	int		*w;
}				t_pars;

/*
**image & widnow structures
*/
typedef struct	s_img
{
	void	*image;
	int		*data;
	int		*bpp;
	int		*size_l;
	int		*endian;
}				t_img;

typedef struct	s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	image;
	int		height;
	int		width;
}				t_win;

/*
**player structures
**play:
** fov: player field of view
** rot: vecteur de direction
** speed: walking speed
** tot_speed: turning speed
*/
typedef struct	s_pos
{
	float	x;
	float	y;
}				t_pos;

typedef struct	s_play
{
	t_pos	p;
	int		fov;
	int		rot;
	int		speed;
	int		rot_speed;
}				t_play;

/*
**minimap structure
**ori: for minimap
*/
typedef struct	s_ori
{
	char	*n;
	char	*s;
	char	*e;
	char	*w;
}				t_ori;

/*
**big boy des structures
**pars: done
**win: malloc?
**player: no need to malloc
**mm: malloc?
*/
typedef struct	s_all
{
	t_pars	pars;
	t_win	win;
	t_play	player;
	t_ori	mm;
}				t_all;

#endif
