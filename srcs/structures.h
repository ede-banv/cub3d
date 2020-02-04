#ifndef STRUCTURES_H
# define STRUCTURES_H

# define MAXRES_X 2560
# define MAXRES_Y 1440

# define WALL_HEIGHT
# define VIEW_HEIGHT

//map structures
typedef struct  s_txtr
{
    char    *no;
    char    *so;
    char    *we;
    char    *ea;
    char    *sprite;
}               t_txtr;

typedef struct  s_pars
{
    int     res[2];
    t_txtr  texture;
    int     f[3];
    int     c[3];
    char    **map;
}               t_pars;

//image & widnow structures
typedef struct  s_img
{
    void    *image;
    int     *data;
    int     *bpp;
    int     *size_l;
    int     *endian;
}               t_img;

typedef struct  s_window
{
    void    *mlx_ptr;
    void    *win_ptr;
    t_img   image;
    int     height;
    int     window;
}               t_window;

//player structures
typedef struct  s_pos
{
    int     x;
    int     y;
}               t_pos;

typedef struct  s_play
{
    t_pos   p;
    int     fov; //taille du field of view
    int     rot; //vecteur de direction du fov
    int     speed; //walking speed
    int     rot_speed; //rotation speed
}               t_play;

//minimap structure
typedef struct  s_ori   //pour minimap
{                       //char * pour le moment, peut changer
    char    *N;
    char    *S;
    char    *E;
    char    *W;
}               t_ori;

//big boy des structures
typedef struct  s_all
{
    t_pars      pars;
    t_window    win;
    t_play      player;
    t_ori       mm;
}               t_all;

#endif