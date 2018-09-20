/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 19:53:22 by azaporoz          #+#    #+#             */
/*   Updated: 2018/09/18 19:53:22 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

/*
** 2500
** 1300
*/
# define WIDTH 970
# define HEIGHT 970
# define VIEW 1
# define C_W 1
# define C_H 1
# define TO_VIEW 1
# define AMBIENT 1
# define POINT 2
# define DIRECT 3
# define SPHERE 1
# define CONE 2
# define CYLI 3
# define PLANE 4
# define EPSILON 0.001

/*
** COLORS IN MLX_IMAGE:
** 1->blue
** 2->green
** 3->red
*/
# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xff170f
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define PINK 0xFF00FF
# define YELLOW 0xfff305
# define MAX_INT 9223372036854775807
# include "SDL.h"
# include "./libft/libft.h"
# include <math.h>

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
	int				a;
}					t_color;

typedef struct		s_vec
{
	double			x;
	double			y;
	double			z;
}					t_vec;

/*
** 1 - sphere
** 2 - cilinder
** 3 - conus
** 4 - plane
*/
typedef struct		s_form
{
	int				type;
	t_vec			coord;
	t_color			col;
	t_vec			rot;
	double			r;
	struct s_form	*next;
}					t_form;

/*
** 1 - ambient
** 2 - point
** 3 - directional
*/
typedef struct		s_light
{
	int				type;
	double			i;
	t_vec			dir;
	t_vec			pos;
	struct s_light	*next;
}					t_light;

typedef struct		s_min
{
	t_form			*cp;
	double			var;
}					t_min;

typedef struct		s_lnorme
{
	double			i;
	double			l_n;
	t_vec			vec_l;
	double			n_dot_l;
	t_light			*p_l;
	t_vec			point;
	t_vec			normal;
}					t_lnorme;

typedef struct		s_fig
{
	double			a;
	double			b;
	double			c;
	double			t1;
	double			t2;
	double			disc;
	t_vec			oc;
}					t_fig;

typedef struct		s_win
{
	t_vec			cam;
	t_vec			m_ray;
	t_form			*form;
	t_light			*light;
	t_vec			dir;
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Event		e;
	int				quit;
	double			tx;
	double			ty;
	t_form			*min_f;
	double			min_v;
	double			done;
	int				done_2;
}					t_win;

/*
** main
*/
void				ray_tracing(t_win *win);

/*
** vectors operations
*/
double				dot(t_vec *v1, t_vec *v2);
t_vec				cross(t_vec *v1, t_vec *v2);
t_vec				vectorscale(double n, t_vec *v);
t_vec				vectorsub(t_vec *v1, t_vec *v2);
t_vec				vectoradd(t_vec a, t_vec b);

/*
** figures formulas
*/
double				sphere(t_win *win, t_form *cp, t_vec *dir);
double				cone(t_win *win, t_form *cp, t_vec *dir);
double				plane(t_win *win, t_form *cp, t_vec *dir);
double				cyli(t_win *win, t_form *cp, t_vec *dir);
void				scene_1(t_win *win);
void				scene_2(t_win *win);
void				scene_3(t_win *win);
void				scene_4(t_win *win);

/*
** error
*/
void				error(char *str);

/*
** add
*/
double				calc_length(t_vec *vec);
t_vec				canvas_to_view(t_win *win, double x, double y);
void				vectornorm(t_vec *v);
#endif
