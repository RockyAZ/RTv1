/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 19:52:40 by azaporoz          #+#    #+#             */
/*   Updated: 2018/09/18 19:52:41 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		put_pixel(t_win *win, int xx, int yy, t_form *cp)
{
	xx = WIDTH / 2 + xx;
	yy = HEIGHT / 2 - yy - 1;
	if (win->done == -2)
	{
		SDL_SetRenderDrawColor(win->ren, 255, 255, 255, 255);
		SDL_RenderDrawPoint(win->ren, xx, yy);
		return ;
	}
	SDL_SetRenderDrawColor(win->ren, cp->col.r * win->done, cp->col.g *\
		win->done, cp->col.b * win->done, cp->col.a);
	SDL_RenderDrawPoint(win->ren, xx, yy);
}

t_lnorme	make_light(t_win *win, double var, t_form *cp)
{
	t_lnorme l;

	l.point = vectoradd(win->cam, vectorscale(var, &win->dir));
	l.normal = vectorsub(&l.point, &cp->coord);
	l.normal = vectorscale(1.0 / calc_length(&l.normal), &l.normal);
	l.p_l = win->light;
	l.i = 0.0;
	return (l);
}

double		calc_light(t_win *win, double var, t_form *cp)
{
	t_lnorme l;

	l = make_light(win, var, cp);
	while (l.p_l)
	{
		l.n_dot_l = 0;
		if (l.p_l->type == AMBIENT)
			l.i += l.p_l->i;
		else
		{
			if (l.p_l->type == POINT)
				l.vec_l = vectorsub(&l.p_l->pos, &l.point);
			else
				l.vec_l = l.p_l->dir;
			l.n_dot_l = dot(&l.normal, &l.vec_l);
			if (l.n_dot_l > 0)
			{
				l.l_n = calc_length(&l.normal);
				l.n_dot_l = dot(&l.normal, &l.vec_l);
				l.i += l.p_l->i * l.n_dot_l / (l.l_n * calc_length(&l.vec_l));
			}
		}
		l.p_l = l.p_l->next;
	}
	return (l.i);
}

double		near_inter(t_win *win, double min_t, double max_t)
{
	t_form	*cp;
	double	var;

	cp = win->form;
	while (cp)
	{
		if (cp->type == SPHERE)
			var = sphere(win, cp, &win->dir);
		else if (cp->type == PLANE)
			var = plane(win, cp, &win->dir);
		else if (cp->type == CONE)
			var = cone(win, cp, &win->dir);
		else if (cp->type == CYLI)
			var = cyli(win, cp, &win->dir);
		if (var >= 0 && var < win->min_v && var >= min_t && var < max_t)
		{
			win->min_f = cp;
			win->min_v = var;
			win->done_2 = 1;
		}
		cp = cp->next;
	}
	if (win->done_2)
		return (calc_light(win, win->min_v, win->min_f));
	return (-1);
}

void		ray_tracing(t_win *win)
{
	double x;
	double y;

	win->done = -1;
	x = -(WIDTH / 2);
	while (x < WIDTH / 2)
	{
		y = -(HEIGHT / 2);
		while (y < HEIGHT / 2)
		{
			win->dir = canvas_to_view(win, x, y);
			win->min_f = win->form;
			win->min_v = MAX_INT;
			win->done = near_inter(win, 1.0, MAX_INT);
			if (win->done >= 0)
				put_pixel(win, x, y, win->min_f);
			else
			{
				win->done = -2;
				put_pixel(win, x, y, win->min_f);
			}
			y++;
		}
		x++;
	}
}
