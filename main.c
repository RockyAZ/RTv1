/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 14:20:15 by azaporoz          #+#    #+#             */
/*   Updated: 2018/06/19 14:20:17 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

int	ft_exit(t_win *win)
{
	(void)win;
	exit(EXIT_SUCCESS);
	return (0);
}

void	main_preparation(t_win *win)
{
	if ((win->mlx_ptr = mlx_init()) == NULL)
		error("mlx init error");
	win->win_ptr = mlx_new_window(win->mlx_ptr, WIDTH, HEIGHT, "RTv1");
	if (win->win_ptr == NULL)
		error("window open error");
	win->cam.x = 0;
	win->cam.y = 0;
	win->cam.z = 0;
win->sp.coord.x = 0;
win->sp.coord.y = -1;
win->sp.coord.z = 3;
win->sp.r = 1;
win->sp.color = RED;
win->light.dir.x = 1;
win->light.dir.y = 4;
win->light.dir.z = 4;
win->light.intensity = 0.4;
}

void	img_preparation(t_win *win)
{
	win->img_ptr = mlx_new_image(win->mlx_ptr, WIDTH, HEIGHT);
	win->ptr = (unsigned char*)mlx_get_data_addr(win->img_ptr, &win->bpp, &win->size_line, &win->endian);
	// mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
	// mlx_destroy_image(win->mlx_ptr, win->img_ptr);
}

int	main(int ac, char **av)
{
	t_win *win;

	if ((win = (t_win*)malloc(sizeof(t_win))) == NULL)
		error("t_win malloc error");
	main_preparation(win);
	img_preparation(win);
	ray_tracing(win);
	// mlx_hook(win->win_ptr, 2, 0, &ft_keyhook, (void*)win);
	// mlx_hook(win->win_ptr, 3, 0, &ft_up_keyhook, (void*)win);
	mlx_hook(win->win_ptr, 17, 0, &ft_exit, (void*)win);
	mlx_loop(win->mlx_ptr);
}
