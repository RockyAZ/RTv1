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

double	sphere(t_win *win, t_form *cp, t_vec *dir)
{
	double discrim;
	t_vec oc;
	double k1;
	double k2;
	double k3;

	double t1;
	double t2;

	oc = vectorsub(&win->cam, &cp->coord);
	k1 = dot(dir, dir);
	k2 = 2.0 * dot(&oc, dir);
	k3 = dot(&oc, &oc) - cp->r * cp->r;
	discrim = k2 * k2 - 4.0 * k1 * k3;
	if (discrim < 0)
		return (-1);
	t1 = (-k2 + sqrt(discrim)) / (2.0 * k1);
	t2 = (-k2 - sqrt(discrim)) / (2.0 * k1);
	if (t1 > t2)
		return (t2);
	return (t1);
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

	t_vec point = vectoradd(win->cam, vectorscale(var, &win->dir));
	t_vec normal = vectorsub(&point, &cp->coord);
	normal = vectorscale(1.0 / calc_length(&normal), &normal);

	vec_l = win->light->dir;
	length_n = calc_length(&normal);
	n_dot_l = dot(&normal, &vec_l);
	i += win->light->intensity * n_dot_l / (length_n * calc_length(&vec_l));
	return (i);
}

void	put_pixel(t_win *win, int xx, int yy, double i, t_form *cp)
{
	xx = WIDTH / 2 + xx;
	yy = HEIGHT / 2 - yy + 1;
	SDL_SetRenderDrawColor(win->ren, cp->col.r * i, cp->col.g * i, cp->col.b * i, cp->col.a);
	SDL_RenderDrawPoint(win->ren, xx, yy);
}

void	ray_tracing(t_win *win)
{
	double x;
	double y;
	double var;
	double min;
	double i;
	int **arr;
	t_form  *cp;

	arr = (int*)malloc()
	cp = win->form->next->next;
	x = -(WIDTH / 2);
	while (x < WIDTH / 2)
	{
		y = -(HEIGHT / 2);
		while (y < HEIGHT / 2)
		{
			// while (cp)
			// {
				win->dir = canvas_to_view(win, x, y);
				if (cp->type == 1)
					var = sphere(win, cp, &win->dir);
				if (var != -1)
				{
					i = calc_light(win, x, y, var, cp);
					// printf("%f\n", i);
					// put_pixel(win, x, y);
					put_pixel(win, x, y, i, cp);
				}
			// plane(win);
			// cone();
			// cyl();
				// cp = cp->next;
			// }
			y++;
		}
		x++;
	}
}
