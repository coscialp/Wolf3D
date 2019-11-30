/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hello_world_mlx.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/19 19:05:44 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/30 16:31:30 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "mlx.h"
#include <unistd.h>

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2

typedef struct s_params
{
    void          *ptr;
    void          *win;
    size_t        x;
    size_t        y;
}               t_params;

int     key_press(int keycode, t_params *mlx)
{
    if (keycode == KEY_ESC)
    {
        mlx_destroy_window(mlx->ptr, mlx->win);
        exit(0);
    }
    return (1);
}

int     mouse_press(int button, int x, int y, t_params *mlx)
{
   if (button == 1)
        mlx_pixel_put(mlx->ptr, mlx->win, x, y, 0x000000);
    return (1);
}

int     ft_close(t_params *mlx)
{
    (void)mlx;
    exit(0);
    return (1);
}

int main(void)
{
    t_params *mlx;

    mlx->x = 0;
    mlx->y = 0;
    if ((mlx->ptr = mlx_init()) == NULL)
        return (0);
    if ((mlx->win = mlx_new_window(mlx->ptr, 1280, 720, "Hello world!")) == NULL)
        return (0);
    while (mlx->x < 1280)
    {
       mlx-> y = 0;
        while (mlx->y < 720)
        {
            mlx_pixel_put(mlx->ptr, mlx->win, mlx->x, mlx->y, 0xFFFFFF);
            mlx->y++;
        }
        mlx->x++;
    }
    mlx_string_put(mlx->ptr, mlx->win, 600, 600, 0x000000, "HELLO WORLD!");
    mlx_key_hook(mlx->win, key_press, mlx);
    mlx_mouse_hook(mlx->win, mouse_press, mlx);
    mlx_hook(mlx->win, 17, 0, ft_close, mlx);
    mlx_loop(mlx->ptr);
    return (1);
}