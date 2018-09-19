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

#ifndef RTV_H
# define RTV_H

/*
** 2500
** 1300
*/
# define WIDTH 970
# define HEIGHT 970

#define VIEW 1
#define C_W 1
#define C_H 1

#define TO_VIEW 1

#define AMBIENT 1
#define POINT 2
#define DIRECT 3

#define SPHERE 1
#define CONE 2
#define CYLI 3
#define PLANE 4

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

#define MAX_INT 9223372036854775807

# include "SDL.h"
# include "./libft/libft.h"
# include <math.h>
#include<stdio.h>

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
	int             type;
	t_vec			coord;
	t_color			col;
	t_vec			rot;
	double			r;
	struct s_form   *next;
}					t_form;
/*
** 1 - ambient
** 2 - point
** 3 - directional
*/

typedef struct		s_light
{
	int 			type;
	double			intensity;
	t_vec			dir;
	t_vec			pos;
	struct s_light	*next;
}					t_light;

typedef struct		s_min
{
	t_form			*cp;
	double			var;
}					t_min;

// typedef struct		s_cam
// {
// 	double			x;
// 	double			y;
// 	double			z;
// }					t_cam;

typedef struct		s_win
{
	// t_cam			*cam;
	t_vec			cam;
	t_vec			m_ray;
	t_form			*form;
	t_light			*light;
	t_vec			dir;
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Event		e;
	int				quit;
	int				forms;
	double			tx;
	double			ty;	
}					t_win;

/*
** main
*/
void				ray_tracing(t_win *win);

/*
** vectors operations
*/
double  			dot(t_vec *v1, t_vec *v2);
t_vec				cross(t_vec *v1, t_vec *v2);
t_vec				vectorscale(double n, t_vec *v);
t_vec				vectorsub(t_vec *v1, t_vec *v2);
void				vectornorm(t_vec *v);

t_vec				vectoradd(t_vec a, t_vec b);

/*
** figures formulas
*/
double				sphere(t_win *win, t_form *cp, t_vec *dir);
double				cone(t_win *win, t_form *cp, t_vec *dir);
double				plane(t_win *win, t_form *cp, t_vec *dir);
double				cyli(t_win *win, t_form *cp, t_vec *dir);

/*
** error
*/
void				error(char *str);
#endif
