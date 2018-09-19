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
	win->form->type = SPHERE;
	win->form->coord.x = 0;
	win->form->coord.y = -1;
	win->form->coord.z = 3;
	win->form->r = 1;
	win->form->col.r = 255;
	win->form->col.g = 0;
	win->form->col.b = 0;
	win->form->col.a = 251;//

	win->form->next = (t_form*)malloc(sizeof(t_form));
	win->form->next->type = SPHERE;
	win->form->next->coord.x = 2;
	win->form->next->coord.y = 0;
	win->form->next->coord.z = 4;
	win->form->next->r = 1;
	win->form->next->col.r = 0;
	win->form->next->col.g = 0;
	win->form->next->col.b = 255;
	win->form->next->col.a = 252;//

	win->form->next->next = (t_form*)malloc(sizeof(t_form));
	win->form->next->next->type = SPHERE;
	win->form->next->next->coord.x = -2;
	win->form->next->next->coord.y = 0;
	win->form->next->next->coord.z = 4;
	win->form->next->next->r = 1;
	win->form->next->next->col.r = 0;
	win->form->next->next->col.g = 255;
	win->form->next->next->col.b = 0;
	win->form->next->next->col.a = 253;//


	win->form->next->next->next = (t_form*)malloc(sizeof(t_form));
	win->form->next->next->next->type = SPHERE;
	win->form->next->next->next->coord.x = 0;
	win->form->next->next->next->coord.y = -5001;
	win->form->next->next->next->coord.z = 0;
	win->form->next->next->next->r = 5000;
	win->form->next->next->next->col.r = 255;
	win->form->next->next->next->col.g = 255;
	win->form->next->next->next->col.b = 0;
	win->form->next->next->next->col.a = 253;//


	win->form->next->next->next->next = NULL;
	win->forms = 4;
}

void	create_light(t_win *win)
{
	win->light = (t_light*)malloc(sizeof(t_light));
	win->light->type = AMBIENT;
	win->light->intensity = 0.2;

	win->light->next = (t_light*)malloc(sizeof(t_light));
	win->light->next->type = POINT;
	win->light->next->pos.x = 2;
	win->light->next->pos.y = 1;
	win->light->next->pos.z = 0;
	win->light->next->intensity = 0.6;

	win->light->next->next = (t_light*)malloc(sizeof(t_light));
	win->light->next->next->type = DIRECT;
	win->light->next->next->dir.x = 1;
	win->light->next->next->dir.y = 4;
	win->light->next->next->dir.z = 4;
	win->light->next->next->intensity = 0.2;
	win->light->next->next->next = NULL;
}

void	create_fig_2(t_win *win)
{
	win->form = (t_form*)malloc(sizeof(t_form));
	win->form->type = PLANE;
	win->form->coord.x = 0;
	win->form->coord.y = -1;
	win->form->coord.z = 3;
	win->form->rot.x = 0;
	win->form->rot.y = -1;
	win->form->rot.z = 0;
	win->form->r = 1;
	win->form->col.r = 255;
	win->form->col.g = 0;
	win->form->col.b = 0;
	win->form->col.a = 251;
	// win->form->next = NULL;

		win->form->next = (t_form*)malloc(sizeof(t_form));
	win->form->next->type = SPHERE;
	win->form->next->coord.x = 2;
	win->form->next->coord.y = 0;
	win->form->next->coord.z = 4;
	win->form->next->r = 1;
	win->form->next->col.r = 0;
	win->form->next->col.g = 0;
	win->form->next->col.b = 255;
	win->form->next->col.a = 252;
	win->form->next->next = NULL;
}

void	create_fig_3(t_win *win)
{
	win->form = (t_form*)malloc(sizeof(t_form));
	win->form->type = CONE;
	win->form->coord.x = 0;
	win->form->coord.y = -1;
	win->form->coord.z = 3;
	win->form->rot.x = -1;
	win->form->rot.y = 0;
	win->form->rot.z = 0;
	win->form->r = 0.5;
	win->form->col.r = 255;
	win->form->col.g = 0;
	win->form->col.b = 0;
	win->form->col.a = 255;
	win->form->next = NULL;

	// 	win->form->next = (t_form*)malloc(sizeof(t_form));
	// win->form->next->type = SPHERE;
	// win->form->next->coord.x = 0;
	// win->form->next->coord.y = -1;
	// win->form->next->coord.z = 3;
	// win->form->next->r = 1;
	// win->form->next->col.r = 0;
	// win->form->next->col.g = 0;
	// win->form->next->col.b = 255;
	// win->form->next->col.a = 255;
	// win->form->next->next = NULL;
}

void	create_fig_4(t_win *win)
{
	win->form = (t_form*)malloc(sizeof(t_form));
	win->form->type = CYLI;
	win->form->coord.x = 0;
	win->form->coord.y = -1;
	win->form->coord.z = 3;
	win->form->rot.x = 0;
	win->form->rot.y = -1;
	win->form->rot.z = 0;
	win->form->r = 0.1;
	win->form->col.r = 255;
	win->form->col.g = 0;
	win->form->col.b = 0;
	win->form->col.a = 255;
	win->form->next = NULL;
}

void	create_fig_5(t_win *win)
{

	win->form = (t_form*)malloc(sizeof(t_form));
	win->form->type = SPHERE;
	win->form->coord.x = 0;
	win->form->coord.y = 1;
	win->form->coord.z = 3;
	win->form->r = 1.3;
	win->form->col.r = 0;
	win->form->col.g = 0;
	win->form->col.b = 255;
	win->form->col.a = 255;

	win->form->next = (t_form*)malloc(sizeof(t_form));
	win->form->next->type = CONE;
	win->form->next->coord.x = 0;
	win->form->next->coord.y = -1;
	win->form->next->coord.z = 3;
	win->form->next->rot.x = 0;
	win->form->next->rot.y = -1;
	win->form->next->rot.z = 0;
	win->form->next->r = 0.5;
	win->form->next->col.r = 0;
	win->form->next->col.g = 255;
	win->form->next->col.b = 0;
	win->form->next->col.a = 255;

	win->form->next->next = (t_form*)malloc(sizeof(t_form));
	win->form->next->next->type = CYLI;
	win->form->next->next->coord.x = 0;
	win->form->next->next->coord.y = -1;
	win->form->next->next->coord.z = 3;
	win->form->next->next->rot.x = 0;
	win->form->next->next->rot.y = -1;
	win->form->next->next->rot.z = 0;
	win->form->next->next->r = 0.1;
	win->form->next->next->col.r = 0;
	win->form->next->next->col.g = 255;
	win->form->next->next->col.b = 255;
	win->form->next->next->col.a = 255;

	win->form->next->next->next = (t_form*)malloc(sizeof(t_form));
	win->form->next->next->next->type = PLANE;
	win->form->next->next->next->coord.x = 1;
	win->form->next->next->next->coord.y = -1;
	win->form->next->next->next->coord.z = 3;
	win->form->next->next->next->rot.x = 0;
	win->form->next->next->next->rot.y = -1;
	win->form->next->next->next->rot.z = 0;
	win->form->next->next->next->r = 1;
	win->form->next->next->next->col.r = 255;
	win->form->next->next->next->col.g = 0;
	win->form->next->next->next->col.b = 0;
	win->form->next->next->next->col.a = 255;

	win->form->next->next->next->next = NULL;
	win->forms = 4;
}


// void	create_fig_center(t_win *win)
// {
// 	win->form = (t_form*)malloc(sizeof(t_form));
// 	win->form->type = SPHERE;
// 	win->form->coord.x = 0;
// 	win->form->coord.y = -1;
// 	win->form->coord.z = 3;
// 	win->form->r = 1;
// 	win->form->col.r = 255;
// 	win->form->col.g = 0;
// 	win->form->col.b = 0;
// 	win->form->col.a = 255;
// 	win->form->next = NULL;
// }

// void	create_fig_left(t_win *win)
// {
// 	win->form = (t_form*)malloc(sizeof(t_form));
// 	win->form->type = SPHERE;
// 	win->form->coord.x = -2;
// 	win->form->coord.y = 0;
// 	win->form->coord.z = 4;
// 	win->form->r = 1;
// 	win->form->col.r = 0;
// 	win->form->col.g = 255;
// 	win->form->col.b = 0;
// 	win->form->col.a = 255;
// 	win->form->next = NULL;
// 	win->forms = 1;
// }

// void	create_fig_dva(t_win *win)
// {
// 	win->form = (t_form*)malloc(sizeof(t_form));
// 	win->form->type = SPHERE;
// 	win->form->coord.x = 0;
// 	win->form->coord.y = -1;
// 	win->form->coord.z = 3;
// 	win->form->r = 1;
// 	win->form->col.r = 255;
// 	win->form->col.g = 0;
// 	win->form->col.b = 0;
// 	win->form->col.a = 255;

// 	win->form->next = (t_form*)malloc(sizeof(t_form));
// 	win->form->next->type = SPHERE;
// 	win->form->next->coord.x = -2;
// 	win->form->next->coord.y = 0;
// 	win->form->next->coord.z = 4;
// 	win->form->next->r = 1;
// 	win->form->next->col.r = 0;
// 	win->form->next->col.g = 255;
// 	win->form->next->col.b = 0;
// 	win->form->next->col.a = 255;
// 	win->form->next->next = NULL;
// }

int	main(int ac, char **av)
{
	t_win *win;

	win = (t_win*)malloc(sizeof(t_win));
	win->cam.x = 0;
	win->cam.y = 0;
	win->cam.z = 0;

	// create_fig_center(win);
	// create_fig_left(win);
	// create_fig_dva(win);

	create_fig(win);
	// create_fig_2(win);
	// create_fig_3(win);
	// create_fig_4(win);
	// create_fig_5(win);

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
	SDL_DestroyRenderer(win->ren);
	SDL_DestroyWindow(win->win);
	// system("leaks RTv1");
	SDL_Quit();
	return (0);
}
	// SDL_SetRenderDrawColor(env.renderer, color.r, color.g, color.b, 255);
	// SDL_RenderDrawPoint(env.renderer, x, y);
	// if ((SDL_Init(SDL_INIT_EVERYTHING) == -1))
		// exit_fail(SDL_GetError(), 1);
	// if ((SDL_CreateWindowAndRenderer(WINDOW_W, WINDOW_H, 0, &env->window, &env->renderer) == -1))
