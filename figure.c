/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 17:13:03 by azaporoz          #+#    #+#             */
/*   Updated: 2018/09/19 17:13:03 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	sphere(t_win *win, t_form *cp, t_vec *dir)
{
	t_fig f;

	f.oc = vectorsub(&win->cam, &cp->coord);
	f.a = dot(dir, dir);
	f.b = 2.0 * dot(&f.oc, dir);
	f.c = dot(&f.oc, &f.oc) - cp->r * cp->r;
	f.disc = f.b * f.b - 4.0 * f.a * f.c;
	if (f.disc < 0)
		return (-1);
	f.t1 = (-f.b + sqrt(f.disc)) / (2.0 * f.a);
	f.t2 = (-f.b - sqrt(f.disc)) / (2.0 * f.a);
	if (f.t1 > f.t2)
		return (f.t2);
	return (f.t1);
}

double	cone(t_win *win, t_form *cp, t_vec *dir)
{
	t_fig f;

	f.oc = vectorsub(&win->cam, &cp->coord);
	vectornorm(&cp->rot);
	f.a = dot(dir, dir) - (1 + pow(tan(cp->r), 2)) *\
	pow(dot(dir, &cp->rot), 2);
	f.b = 2 * (dot(dir, &f.oc) - (1 + pow(tan(cp->r), 2)) *\
		dot(dir, &cp->rot) * dot(&f.oc, &cp->rot));
	f.c = dot(&f.oc, &f.oc) - (1 + pow(tan(cp->r), 2)) *\
	pow(dot(&f.oc, &cp->rot), 2);
	f.disc = f.b * f.b - 4 * f.a * f.c;
	if (f.disc < 0)
		return (-1);
	f.t1 = (-f.b + sqrtf(f.disc)) / (2 * f.a);
	f.t2 = (-f.b - sqrtf(f.disc)) / (2 * f.a);
	if (f.t1 > f.t2)
		f.t1 = f.t2;
	return (f.t1);
}

double	plane(t_win *win, t_form *cp, t_vec *dir)
{
	double t1;

	t1 = ((dot(&cp->rot, &cp->coord) - dot(&cp->rot, &win->cam)) /\
		dot(&cp->rot, dir));
	if (t1 < 0.0001)
		return (-1);
	return (t1);
}

double	cyli(t_win *win, t_form *cp, t_vec *dir)
{
	t_fig f;

	f.oc = vectorsub(&win->cam, &cp->coord);
	vectornorm(&cp->rot);
	f.a = dot(dir, dir) - pow(dot(dir, &cp->rot), 2);
	f.b = 2 * (dot(dir, &f.oc) - (dot(dir, &cp->rot) * dot(&f.oc, &cp->rot)));
	f.c = dot(&f.oc, &f.oc) - pow(dot(&f.oc, &cp->rot), 2) - pow(cp->r, 2);
	f.disc = f.b * f.b - 4 * f.a * f.c;
	if (f.disc < 0)
		return (-1);
	f.t1 = (-f.b + sqrtf(f.disc)) / (2 * f.a);
	f.t2 = (-f.b - sqrtf(f.disc)) / (2 * f.a);
	if (f.t1 > f.t2)
		f.t1 = f.t2;
	return (f.t1);
}
