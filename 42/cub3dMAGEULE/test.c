#include "cub3d.h"

int main()
{
    void *mlx;
    void *window;

    mlx = mlx_init();
    window = mlx_new_window(mlx, 1000, 1000, "title");
    int i = 100;
    int y = 100;
    int color = 100;
    while(1)
    {
        color = color + 20;
        while(i++ < 200)
            mlx_pixel_put(mlx, window, i, y, color);
        while(y++ < 200)
            mlx_pixel_put(mlx, window, i, y, 65030);
        while(i-- > 100)
            mlx_pixel_put(mlx, window, i, y, color);
        while(y-- > 100)
            mlx_pixel_put(mlx, window, i, y, 65030);
        mlx_loop(mlx);
    }
    
    return(0);
}