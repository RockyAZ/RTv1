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
	yy = HEIGHT / 2 - yy + 1;
	if (i == -2)
	{
		SDL_SetRenderDrawColor(win->ren, 255, 255, 255, 255);
		SDL_RenderDrawPoint(win->ren, xx, yy);
		return ;
	}
	SDL_SetRenderDrawColor(win->ren, cp->col.r * i, cp->col.g * i, cp->col.b * i, cp->col.a);
	SDL_RenderDrawPoint(win->ren, xx, yy);
}






// double	cylinder(t_th *mlx, t_obj *tmp, t_vec ray, t_vec pos)
// {
// 	double disc;

// 	mlx->dist = ft_vectorsub(&pos, &tmp->pos);
// 	ft_vectornorm(&tmp->rot);
// 	mlx->a = ft_vectordot(&ray, &ray) - pow(ft_vectordot(&ray, &tmp->rot), 2);
// 	mlx->b = 2 * (ft_vectordot(&ray, &mlx->dist) -
// 		(ft_vectordot(&ray, &tmp->rot) * ft_vectordot(&mlx->dist, &tmp->rot)));
// 	mlx->c = ft_vectordot(&mlx->dist, &mlx->dist) -
// 		pow(ft_vectordot(&mlx->dist, &tmp->rot), 2) - pow(tmp->size, 2);
// 	disc = mlx->b * mlx->b - 4 * mlx->a * mlx->c;
// 	if (disc < 0)
// 		return (-1);
// 	mlx->t0 = (-mlx->b + sqrtf(disc)) / (2 * mlx->a);
// 	mlx->t1 = (-mlx->b - sqrtf(disc)) / (2 * mlx->a);
// 	if (mlx->t0 > mlx->t1)
// 		mlx->t0 = mlx->t1;
// 	return (mlx->t0);
// }

// double	calc_light(t_win *win, int x, int y, double var, t_form *cp)
// {
// 	double i = 0.0;
// 	double length_n;
// 	t_vec	vec_l;
// 	double n_dot_l;

// 	t_vec point = vectoradd(win->cam, vectorscale(var, &win->dir));
// 	t_vec normal = vectorsub(&point, &cp->coord);
// 	normal = vectorscale(1.0 / calc_length(&normal), &normal);

// 	vec_l = win->light->dir;
// 	length_n = calc_length(&normal);
// 	n_dot_l = dot(&normal, &vec_l);
// 	i += win->light->intensity * n_dot_l / (length_n * calc_length(&vec_l));
// 	return (i);
// }

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
// printf("::::::%d::::::\n", cp->col.a);
	p_l = win->light;
	while (p_l)
	{
		n_dot_l = 0;
		if (p_l->type == AMBIENT)
		{
// printf("AMBIENT\n");
			i += p_l->intensity;
		}
		else
		{
			if  (p_l->type == POINT)
			{
// printf("POINT\n");
				vec_l = vectorsub(&p_l->pos, &point);
			}
			else
			{
// printf("DIST\n");
				vec_l = p_l->dir;
			}
			// printf("X:%f\nY:%f\nZ:%f\n\n", vec_l.x, vec_l.y, vec_l.z);
			n_dot_l = dot(&normal, &vec_l);
// printf("n_dot:::%f\n", n_dot_l);
			if (n_dot_l > 0)
			{
// printf("THERE\n");
				length_n = calc_length(&normal);
				n_dot_l = dot(&normal, &vec_l);
				i += p_l->intensity * n_dot_l / (length_n * calc_length(&vec_l));
			}
		}
		p_l = p_l->next;
	}
// printf("I::%f\n", i);
	return (i);
}


// var ComputeLighting = function(point, normal) {
//   var intensity = 0;
//   var length_n = Length(normal);  // Should be 1.0, but just in case...

//   for (var i = 0; i < lights.length; i++)
//   {
//     var light = lights[i];
//     if (light.ltype == Light.AMBIENT)
//     {
//       intensity += light.intensity;
//     }
//     else
//     {
//       var vec_l;
//       if (light.ltype == Light.POINT)
//       {
//     	vec_l = Subtract(light.position, point);
//       }
//       else
//       {  // Light.DIRECTIONAL
//     	vec_l = light.position;
//       }
//       var n_dot_l = DotProduct(normal, vec_l);
//       if (n_dot_l > 0)
//       {
//     	intensity += light.intensity * n_dot_l / (length_n * Length(vec_l));
//       }
//     }
//   }

//   return intensity;
// }

// var point = Add(origin, Multiply(closest_t, direction));
//   var normal = Subtract(point, closest_sphere.center);
//   normal = Multiply(1.0 / Length(normal), normal);

//   return Multiply(ComputeLighting(point, normal), closest_sphere.color);

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
double	plane(t_win *win, t_form *cp, t_vec *dir)
{
	double t1;
	double t2;


	t1 = ((dot(&cp->rot, &cp->coord) - dot(&cp->rot, &win->cam)) / dot(&cp->rot, dir));
	if (t1 < 0.0001)
		return (-1);
	return (t1);
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


void	ray_tracing(t_win *win)
{
	double x;
	double y;
	double var;
	double i;
	int done;
	t_form  *cp;
	t_min	res;

	res.cp = cp;
	res.var = MAX_INT;
	x = -(WIDTH / 2);
	while (x < WIDTH / 2)
	{
		y = -(HEIGHT / 2);
		while (y < HEIGHT / 2)
		{
			cp = win->form;
			res.cp = win->form;
			res.var = MAX_INT;
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
				if (var != -1 && var < res.var)
				{
					res.cp = cp;
					res.var = var;
					done = 1;
				}
				cp = cp->next;
// printf("\n\n");
			}
// printf("=========\n");
			if (done)
			{
				// printf("%d\n", res.cp->col.a);
				i = calc_light(win, x, y, var, res.cp);
				put_pixel(win, x, y, i, res.cp);
			}
			else
				put_pixel(win, x, y, -2, res.cp);
			y++;
		}
		x++;
	}
	// exit(0);
}
