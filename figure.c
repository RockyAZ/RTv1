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

double	cone(t_win *win, t_form *cp, t_vec *dir)
{
	double	disc;
	t_vec oc;
	double a;
	double b;
	double c;

	double t1;
	double t2;

	oc = vectorsub(&win->cam, &cp->coord);
	vectornorm(&cp->rot);
	a = dot(dir, dir) - (1 + pow(tan(cp->r), 2)) *	pow(dot(dir, &cp->rot), 2);
	b = 2 * (dot(dir, &oc) - (1 + pow(tan(cp->r), 2)) * dot(dir, &cp->rot) * dot(&oc, &cp->rot));
	c = dot(&oc, &oc) - (1 +pow(tan(cp->r), 2)) * pow(dot(&oc, &cp->rot), 2);
	disc = b * b - 4 * a * c;
	if (disc < 0)
		return (-1);
	t1 = (-b + sqrtf(disc)) / (2 * a);
	t2 = (-b - sqrtf(disc)) / (2 * a);
	if (t1 > t2)
		t1 = t2;
	return (t1);
}

double	plane(t_win *win, t_form *cp, t_vec *dir)
{
	double t1;
	double t2;


	t1 = ((dot(&cp->rot, &cp->coord) - dot(&cp->rot, &win->cam)) / dot(&cp->rot, dir));
	if (t1 < 0.0001)
		return (-1);
	return (t1);
}

double	cyli(t_win *win, t_form *cp, t_vec *dir)
{
	double disc;
	t_vec oc;
	double a;
	double b;
	double c;

	double t1;
	double t2;

	oc = vectorsub(&win->cam, &cp->coord);
	vectornorm(&cp->rot);
	a = dot(dir, dir) - pow(dot(dir, &cp->rot), 2);
	b = 2 * (dot(dir, &oc) - (dot(dir, &cp->rot) * dot(&oc, &cp->rot)));
	c = dot(&oc, &oc) - pow(dot(&oc, &cp->rot), 2) - pow(cp->r, 2);
	disc = b * b - 4 * a * c;
	if (disc < 0)
		return (-1);
	t1 = (-b + sqrtf(disc)) / (2 * a);
	t2 = (-b - sqrtf(disc)) / (2 * a);
	if (t1 > t2)
		t1 = t2;
	return (t1);
}