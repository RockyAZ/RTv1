/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 16:56:58 by azaporoz          #+#    #+#             */
/*   Updated: 2018/09/17 16:56:59 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

// d - расстоярие до плоскости проекции

double sCanvasToViewport(x, y)
{
	return (x*Vw/Cw, y*Vh/Ch, d);
}

double	IntersectRaySphere(O, D, sphere)
{
	C = sphere.center
	r = sphere.radius
	oc = O - C

	k1 = dot(D, D)
	k2 = 2*dot(OC, D)
	k3 = dot(OC, OC) - r*r

	discriminant = k2*k2 - 4*k1*k3
	if discriminant < 0:
		return inf, inf

	t1 = (-k2 + sqrt(discriminant)) / (2*k1)
	t2 = (-k2 - sqrt(discriminant)) / (2*k1)
	return t1, t2
}


double	ft_inter_sphere(t_th *mlx, t_obj *tmp, t_vec ray, t_vec pos)
{
	double disc;

	mlx->dist = ft_vectorsub(&pos, &tmp->pos);
	mlx->a = ft_vectordot(&ray, &ray);
	mlx->b = 2 * ft_vectordot(&ray, &mlx->dist);
	mlx->c = ft_vectordot(&mlx->dist, &mlx->dist) - (tmp->size * tmp->size);
	disc = mlx->b * mlx->b - 4 * mlx->a * mlx->c;
	if (disc < 0)
		return (-1);
	mlx->t0 = (-mlx->b + sqrtf(disc)) / (2 * mlx->a);
	mlx->t1 = (-mlx->b - sqrtf(disc)) / (2 * mlx->a);
	if (mlx->t0 > mlx->t1)
		mlx->t0 = mlx->t1;
	return (mlx->t0);
}

double sphere(t_win *win, int x, int y)
{
	t_vec disc;
	double dist;
	double a;
	double b;
	double c;

	dist = 
	a = 
}

void	ray_tracing(t_win *win)
{
	int x;
	int y;

	x = 0;
	y = 0;

	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			sphere(win, x, y);
			// plane(win);
			// cone();
			// cyl();
			x++;
		}
		y++;
	}
}
