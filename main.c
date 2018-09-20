/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 19:52:37 by azaporoz          #+#    #+#             */
/*   Updated: 2018/09/18 19:52:37 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	make_win(t_win *win)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	win->win = SDL_CreateWindow("RTv1", 0, 0, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	win->ren = SDL_CreateRenderer(win->win, -1, SDL_RENDERER_ACCELERATED\
									| SDL_RENDERER_PRESENTVSYNC);
	win->cam.x = 0;
	win->cam.y = 0;
	win->cam.z = 0;
}

void	what_is(t_win *win, int arg)
{
	if (arg == 1)
		scene_1(win);
	else if (arg == 2)
		scene_2(win);
	else if (arg == 3)
		scene_3(win);
	else if (arg == 4)
		scene_4(win);
}

void	checker_cam(t_win *win)
{
	if (win->cam.x >= 4)
		win->cam.x -= 0.1;
	if (win->cam.x <= -4)
		win->cam.x += 0.1;
	if (win->cam.y >= 4)
		win->cam.y -= 0.1;
	if (win->cam.y <= -4)
		win->cam.y += 0.1;
}

void	event_touch(t_win *win)
{
	while (SDL_PollEvent(&win->e))
	{
		if (win->e.type == SDL_KEYDOWN &&\
			win->e.key.keysym.sym == SDLK_ESCAPE)
			win->quit = 1;
		if (win->e.type == SDL_QUIT)
			win->quit = 1;
		if (win->e.type == SDL_KEYDOWN &&\
			win->e.key.keysym.sym == SDLK_UP)
			win->cam.y += 0.1;
		if (win->e.type == SDL_KEYDOWN &&\
			win->e.key.keysym.sym == SDLK_DOWN)
			win->cam.y -= 0.1;
		if (win->e.type == SDL_KEYDOWN &&\
			win->e.key.keysym.sym == SDLK_RIGHT)
			win->cam.x += 0.1;
		if (win->e.type == SDL_KEYDOWN &&\
			win->e.key.keysym.sym == SDLK_LEFT)
			win->cam.x -= 0.1;
	}
	if (win->e.type == SDL_KEYDOWN && (win->e.key.keysym.sym == SDLK_UP ||\
		win->e.key.keysym.sym == SDLK_DOWN || win->e.key.keysym.sym ==\
		SDLK_LEFT || win->e.key.keysym.sym == SDLK_RIGHT))
		checker_cam(win);
}

int		main(int ac, char **av)
{
	t_win	*win;
	int		arg;

	win = (t_win*)malloc(sizeof(t_win));
	make_win(win);
	if (ac != 2)
		error("MUST BE ONE ARG WITH SOME NUMBER AT THE BEGINNING\n");
	if (av[1][1] != '\0')
		error("MUST BE ONE ARG WITH ONE NUMBER AT THE BEGINNING\n");
	arg = ft_atoi(&av[1][0]);
	if (arg != 1 && arg != 2 && arg != 3 && arg != 4)
		error("SCENE IS:1-2-3-4\n");
	what_is(win, arg);
	while (win->quit == 0)
	{
		SDL_SetRenderDrawColor(win->ren, 0, 0, 0, 0);
		SDL_RenderClear(win->ren);
		ray_tracing(win);
		event_touch(win);
		SDL_RenderPresent(win->ren);
	}
	system("leaks RTv1");
	SDL_Quit();
	return (0);
}
