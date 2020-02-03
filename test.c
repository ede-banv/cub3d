#include "./minilibx_mms_20191207_beta/mlx.h"
#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnbr(int n)
{
    long int nb;
    
    nb = n;
    if (nb < 0)
    {
        nb *= -1;
        ft_putchar('-');
    }
    if (nb <= 9)
        ft_putchar(nb + 48);
    else
    {
        ft_putnbr(nb / 10);
        ft_putnbr(nb % 10);
    }
}

int deal_key(int key, void *param)
{
    ft_putnbr(key);
    ft_putchar(' ');
    return (0);
}

int test()
{
    int res;
    char *tab;

    tab = (char *)&res;
    tab[0] = 0;
    tab[1] = 1;
    tab[2] = 255;
    tab[3] = 1;
    return (res);
}


int main()
{
    void *mlx_ptr;
    void *win_ptr;
    void *image;
    int *data;
    int bpp;
    int sizel;
    int endian;
    int res = test();
    int i = 1000;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "mlx 42");
 /*   r = mlx_pixel_put(mlx_ptr, win_ptr, 100, 150, res);
    mlx_key_hook(win_ptr, deal_key, (void *)0);
 */
    image = mlx_new_image(mlx_ptr, 1000, 1000);
    data = (int *)mlx_get_data_addr(image, &bpp, &sizel, &endian);
   // while (i++ - 1000 < 50)
        data[i*500] = 0xFF0084;
    mlx_put_image_to_window(mlx_ptr, win_ptr, image, 0, 0);
    mlx_loop(mlx_ptr);
   return (0);
}