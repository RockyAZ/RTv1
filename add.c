/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 15:29:07 by azaporoz          #+#    #+#             */
/*   Updated: 2018/09/20 15:29:07 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	vectornorm(t_vec *v)
{
	double	n;

	n = 1.0 / sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
	v->x *= n;
	v->y *= n;
	v->z *= n;
}

double	calc_length(t_vec *vec)
{
	return (sqrt(dot(vec, vec)));
}

t_vec	canvas_to_view(t_win *win, double x, double y)
{
	t_vec res;

	res.x = x * (double)VIEW / (double)WIDTH;
	res.y = y * (double)VIEW / (double)HEIGHT;
	res.z = (double)TO_VIEW;
	win->done_2 = 0;
	return (res);
}

void	error(char *str)
{
	ft_putstr(str);
	exit(0);
}
