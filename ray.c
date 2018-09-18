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

// double sCanvasToViewport(x, y)
// {
// 	return (x*Vw/Cw, y*Vh/Ch, d);
// }

// double	IntersectRaySphere(O, D, sphere)
// {
// 	C = sphere.center
// 	r = sphere.radius
// 	oc = O - C

// 	k1 = dot(D, D)
// 	k2 = 2*dot(OC, D)
// 	k3 = dot(OC, OC) - r*r

// 	discriminant = k2*k2 - 4*k1*k3
// 	if discriminant < 0:
// 		return inf, inf

// 	t1 = (-k2 + sqrt(discriminant)) / (2*k1)
// 	t2 = (-k2 - sqrt(discriminant)) / (2*k1)
// 	return t1, t2
// }


// double	ft_inter_sphere(t_th *mlx, t_obj *tmp, t_vec ray, t_vec pos)
// {
// 	double disc;

// 	mlx->dist = ft_vectorsub(&pos, &tmp->pos);
// 	mlx->a = ft_vectordot(&ray, &ray);
// 	mlx->b = 2 * ft_vectordot(&ray, &mlx->dist);
// 	mlx->c = ft_vectordot(&mlx->dist, &mlx->dist) - (tmp->size * tmp->size);
// 	disc = mlx->b * mlx->b - 4 * mlx->a * mlx->c;
// 	if (disc < 0)
// 		return (-1);
// 	mlx->t0 = (-mlx->b + sqrtf(disc)) / (2 * mlx->a);
// 	mlx->t1 = (-mlx->b - sqrtf(disc)) / (2 * mlx->a);
// 	if (mlx->t0 > mlx->t1)
// 		mlx->t0 = mlx->t1;
// 	return (mlx->t0);
// }

void		draw_point(int xx, int yy, t_win *win, double color)
{
	xx = WIDTH / 2 + xx;
	yy = HEIGHT / 2 - yy + 1;
// printf("%d\n%d\n", xx, yy);
	int i;
	if (xx < WIDTH && yy < HEIGHT)
	{
		i = (xx * 4) + (yy * win->size_line);
		if (color > 0)
		{
			win->ptr[i] = 255 * color;
			win->ptr[++i] = 255 * color;
			win->ptr[++i] = 255 * color;
		}
		else
		{
			win->ptr[i] = 255;
			win->ptr[++i] = 255;
			win->ptr[++i] = 255;
		}			
	// win->ptr[++i] = color >> 8;
	// win->ptr[++i] = color >> 16;
	}
}

t_vec	canvas_to_view(t_win *win, double x, double y)
{
	t_vec res;

	res.x = x * (double)VIEW / (double)WIDTH;
	res.y = y * (double)VIEW / (double)HEIGHT;
	res.z = (double)TO_VIEW;
	return (res);
}
void	print(t_vec *v)
{
	printf("X:%f\nY:%f\nZ:%f\n", v->x, v->y, v->z);
}
double	sphere(t_win *win, t_vec *dir)
{
	double discrim;
	t_vec oc;
	double k1;
	double k2;
	double k3;

	double t1;
	double t2;

	oc = vectorsub(&win->cam, &win->sp.coord);
	k1 = dot(dir, dir);
	k2 = 2.0 * dot(&oc, dir);
	k3 = dot(&oc, &oc) - win->sp.r * win->sp.r;
	discrim = k2 * k2 - 4.0 * k1 * k3;
	if (discrim < 0)
		return (-1);
	t1 = (-k2 + sqrt(discrim)) / (2.0 * k1);
	t2 = (-k2 - sqrt(discrim)) / (2.0 * k1);
	if (t1 > t2)
		return (t2);
	return (t1);
}

void	put_pixel(t_win *win, int xx, int yy)
{
	xx = WIDTH / 2 + xx;
	yy = HEIGHT / 2 - yy + 1;
	mlx_pixel_put(win->mlx_ptr, win->win_ptr, xx, yy, RED);
}

// var Length = function(vec) {
//   return Math.sqrt(DotProduct(vec, vec));
// }

double	calc_length(t_vec *vec)
{
	return (sqrt(dot(vec, vec)));
}

double	calc_light(t_win *win, int x, int y, double var)
{
	double i = 0.0;
	double length_n;
	t_vec	vec_l;
	double n_dot_l;

	t_vec point = vectoradd(win->cam, vectorscale(var, &win->dir));
	t_vec normal = vectorsub(&point, &win->sp.coord);
	normal = vectorscale(1.0 / calc_length(&normal), &normal);

	vec_l = win->light.dir;
	length_n = calc_length(&normal);
	n_dot_l = dot(&normal, &vec_l);
	i += win->light.intensity * n_dot_l / (length_n * calc_length(&vec_l));
	return (i);
}

void	ray_tracing(t_win *win)
{
	double x;
	double y;
	double var;

double i;
	x = -(WIDTH / 2);
	while (x < WIDTH / 2)
	{
		y = -(HEIGHT / 2);
		while (y < HEIGHT / 2)
		{
			win->dir = canvas_to_view(win, x, y);
			var = sphere(win, &win->dir);
			if (var != -1)
			{
				i = calc_light(win, x, y, var);
				// printf("%f\n", i);
				// put_pixel(win, x, y);
				draw_point(x, y, win, i);
			}
				// put_pixel(win, x, y);
				// draw_point(x, y, win, RED);
			// plane(win);
			// cone();
			// cyl();
			y++;
		}
		x++;
	}
	// printf("PP2:%d\n", pp2);
	// exit(0);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
	// mlx_destroy_image(win->mlx_ptr, win->img_ptr);
}
