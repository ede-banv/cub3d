/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 19:54:24 by ede-banv          #+#    #+#             */
/*   Updated: 2020/03/09 20:42:26 by ede-banv         ###   ########.fr       */
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
	int		bpp;
	int		size_l;
	int		endian;
	int		lineh;
	int		dstart;
	int		dend;
}				t_img;

typedef struct	s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
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
typedef struct	s_vec
{
	double	x;
	double	y;
}				t_vec;

/*
**p is the position of the player
**dir is the direction vector of the player
**plane is the plane vector (corresponds to half the plane)
**raydir corresponds to the vector of the position of where the ray cuts the plane
** so the vector of the direction w the ray
**map has the current square of the map the ray is in
**deltadist is the ray distance between one y(or x) coord and the other
**pwd is the var taht has the dist of the wall
**hit records if there was a wall
**side records which side (NS/EW) was hit
**sidedist is the dist from the ray start position to the first side (x or y)
**step is to know whether the ray is going in a positive or negative dir. is 1 or -1
**
*/
typedef struct	s_play
{
	t_vec	p;
	t_vec	dir;
	t_vec	plane;
	t_vec	raydir;
	int		mapx;
	int		mapy;
	t_vec	deltadist;
	double	pwd;
	int		hit;
	int		side;
	t_vec	sidedist;
//	t_vec	step;
	int		stepx;
	int		stepy;
//	int		fov;
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
