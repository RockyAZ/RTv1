/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:45:49 by azaporoz          #+#    #+#             */
/*   Updated: 2018/09/17 14:45:50 by azaporoz         ###   ########.fr       */
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

# include "./libft/libft.h"
# include "keys.h"
# include <mlx.h>
# include <math.h>
#include<stdio.h>
typedef struct		s_vec
{
	double			x;
	double			y;
	double			z;
}					t_vec;

typedef struct		s_sphere
{
	t_vec			coord;
	int				color;
	int				r;
}					t_sphere;

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
	t_sphere		sp;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				bpp;
	int				size_line;
	int				endian;
	unsigned char	*ptr;
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
t_vec				vectorscale(t_vec *v, float n);
t_vec				vectorsub(t_vec *v1, t_vec *v2);
void				vectornorm(t_vec *v);

/*
** error
*/
void				error(char *str);
#endif
