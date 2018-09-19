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

t_vec	canvas_to_view(t_win *win, double x, double y)
{
	t_vec res;

	res.x = x * (double)VIEW / (double)WIDTH;
	res.y = y * (double)VIEW / (double)HEIGHT;
	res.z = (double)TO_VIEW;
	return (res);
}

void	put_pixel(t_win *win, int xx, int yy, double i, t_form *cp)
{
	xx = WIDTH / 2 + xx;
	yy = HEIGHT / 2 - yy - 1;
	if (i == -2)
	{
		SDL_SetRenderDrawColor(win->ren, 255, 255, 255, 255);
		SDL_RenderDrawPoint(win->ren, xx, yy);
		return ;
	}
	SDL_SetRenderDrawColor(win->ren, cp->col.r * i, cp->col.g * i, cp->col.b * i, cp->col.a);
	SDL_RenderDrawPoint(win->ren, xx, yy);
}

double	calc_length(t_vec *vec)
{
	return (sqrt(dot(vec, vec)));
}

double	calc_light(t_win *win, int x, int y, double var, t_form *cp)
{
	double i = 0.0;
	double length_n;
	t_vec	vec_l;
	double n_dot_l;
	t_light *p_l;

	t_vec point = vectoradd(win->cam, vectorscale(var, &win->dir));
	t_vec normal = vectorsub(&point, &cp->coord);
	normal = vectorscale(1.0 / calc_length(&normal), &normal);
	p_l = win->light;
	while (p_l)
	{
		n_dot_l = 0;
		if (p_l->type == AMBIENT)
		{
			i += p_l->intensity;
		}
		else
		{
			if  (p_l->type == POINT)
			{
				vec_l = vectorsub(&p_l->pos, &point);
			}
			else
			{
				vec_l = p_l->dir;
			}
			n_dot_l = dot(&normal, &vec_l);
			if (n_dot_l > 0)
			{
				length_n = calc_length(&normal);
				n_dot_l = dot(&normal, &vec_l);
				i += p_l->intensity * n_dot_l / (length_n * calc_length(&vec_l));
			}
		}
		p_l = p_l->next;
	}
	return (i);
}

// double	near_inter(t_win,)

void	ray_tracing(t_win *win)
{
	double x;
	double y;
	double var;
	double i;
	int done;
	t_form  *cp;
	// t_min	res;
t_form *min_f;
double min_v;

	x = -(WIDTH / 2);
	while (x < WIDTH / 2)
	{
		y = -(HEIGHT / 2);
		while (y < HEIGHT / 2)
		{
			cp = win->form;
			min_f = cp;
			min_v = MAX_INT;
			done = 0;
			i = -1;
			win->dir = canvas_to_view(win, x, y);
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
				if (var != -1.0 && var < min_v)
				if (var >= 0 && var < min_v)
				{
					min_f = cp;
					min_v = var;
					done = 1;
				}
				cp = cp->next;
			}
			if (done)
			{
				i = calc_light(win, x, y, min_v, min_f);
				put_pixel(win, x, y, i, min_f);
			}
			else
				put_pixel(win, x, y, -2, min_f);
			y++;
		}
		x++;
	}
}
