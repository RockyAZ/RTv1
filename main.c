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

void	create_fig(t_win *win)
{
	win->form = (t_form*)malloc(sizeof(t_form));
	win->form->type = 1;
	win->form->coord.x = 0;
	win->form->coord.y = -1;
	win->form->coord.z = 3;
	win->form->r = 1;
	win->form->col.r = 255;
	win->form->col.g = 0;
	win->form->col.b = 0;
	win->form->col.a = 255;

	win->form->next = (t_form*)malloc(sizeof(t_form));
	win->form->next->type = 1;
	win->form->next->coord.x = 2;
	win->form->next->coord.y = 0;
	win->form->next->coord.z = 4;
	win->form->next->r = 1;
	win->form->next->col.r = 0;
	win->form->next->col.g = 0;
	win->form->next->col.b = 255;
	win->form->next->col.a = 255;

	win->form->next->next = (t_form*)malloc(sizeof(t_form));
	win->form->next->next->type = 1;
	win->form->next->next->coord.x = -2;
	win->form->next->next->coord.y = 0;
	win->form->next->next->coord.z = 4;
	win->form->next->next->r = 1;
	win->form->next->next->col.r = 0;
	win->form->next->next->col.g = 255;
	win->form->next->next->col.b = 0;
	win->form->next->next->col.a = 255;

	win->form->next->next->next = NULL;
	win->forms = 3;
}

void	create_light(t_win *win)
{
	win->light = (t_light*)malloc(sizeof(t_light));
	win->light->type = 1;
	win->light->dir.x = 1;
	win->light->dir.y = 4;
	win->light->dir.z = 4;
	win->light->intensity = 0.4;	
}

int	main(int ac, char **av)
{
	t_win *win;

	win = (t_win*)malloc(sizeof(t_win));
	create_fig(win);
	create_light(win);
	SDL_Init(SDL_INIT_EVERYTHING);
	win->win = SDL_CreateWindow("RTv1", 0, 0, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	win->ren = SDL_CreateRenderer(win->win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	// win->screen = SDL_CreateTexture(win->ren, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_TARGET, WIDTH, HEIGHT);
	// SDL_SetTextureBlendMode(win->screen, SDL_BLENDMODE_BLEND);

	while (win->quit == 0)
	{
		SDL_SetRenderDrawColor(win->ren, 0, 0, 0, 0);
		SDL_RenderClear(win->ren);
		ray_tracing(win);
		while (SDL_PollEvent(&win->e))
		{
			if (win->e.type == SDL_KEYDOWN && win->e.key.keysym.sym == SDLK_ESCAPE)
				win->quit = 1;
			if (win->e.type == SDL_QUIT)
				win->quit = 1;
		}
		// SDL_UpdateTexture(win->screen, NULL, win->buffer[0], WIDTH << 2);
		// SDL_RenderCopy(win->ren, win->screen, NULL, NULL);
		SDL_RenderPresent(win->ren);
	}
	// SDL_DestroyRenderer(win->ren);
	// SDL_DestroyWindow(win->win);
	SDL_Quit();
	return (0);
}
	// SDL_SetRenderDrawColor(env.renderer, color.r, color.g, color.b, 255);
	// SDL_RenderDrawPoint(env.renderer, x, y);
	// if ((SDL_Init(SDL_INIT_EVERYTHING) == -1))
		// exit_fail(SDL_GetError(), 1);
	// if ((SDL_CreateWindowAndRenderer(WINDOW_W, WINDOW_H, 0, &env->window, &env->renderer) == -1))
