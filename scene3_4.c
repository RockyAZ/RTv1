/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene3_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 13:22:59 by azaporoz          #+#    #+#             */
/*   Updated: 2018/09/20 13:22:59 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	light_2(t_win *win)
{
	win->light = (t_light*)malloc(sizeof(t_light));
	win->light->type = AMBIENT;
	win->light->i = 0.2;
	win->light->next = (t_light*)malloc(sizeof(t_light));
	win->light->next->type = POINT;
	win->light->next->pos.x = 2;
	win->light->next->pos.y = 1;
	win->light->next->pos.z = 0;
	win->light->next->i = 0.6;
	win->light->next->next = (t_light*)malloc(sizeof(t_light));
	win->light->next->next->type = DIRECT;
	win->light->next->next->dir.x = 1;
	win->light->next->next->dir.y = 4;
	win->light->next->next->dir.z = 4;
	win->light->next->next->i = 0.2;
	win->light->next->next->next = NULL;
}

void	scene_3(t_win *win)
{
	win->form = (t_form*)malloc(sizeof(t_form));
	win->form->type = CYLI;
	win->form->coord.x = 0;
	win->form->coord.y = -1;
	win->form->coord.z = 3;
	win->form->rot.x = 0;
	win->form->rot.y = -1;
	win->form->rot.z = 0;
	win->form->r = 0.1;
	win->form->col.r = 255;
	win->form->col.g = 0;
	win->form->col.b = 0;
	win->form->col.a = 255;
	win->form->next = (t_form*)malloc(sizeof(t_form));
	win->form->next->type = SPHERE;
	win->form->next->coord.x = 2;
	win->form->next->coord.y = 0;
	win->form->next->coord.z = 4;
	win->form->next->r = 1;
	win->form->next->col.r = 0;
	win->form->next->col.g = 0;
	win->form->next->col.b = 255;
	win->form->next->col.a = 255;
	win->form->next->next = NULL;
	light_2(win);
}

void	scene_4b(t_win *win)
{
	win->form->next->next->next = (t_form*)malloc(sizeof(t_form));
	win->form->next->next->next->type = PLANE;
	win->form->next->next->next->coord.x = 0;
	win->form->next->next->next->coord.y = -1;
	win->form->next->next->next->coord.z = 3;
	win->form->next->next->next->rot.x = 0;
	win->form->next->next->next->rot.y = -1;
	win->form->next->next->next->rot.z = 0;
	win->form->next->next->next->r = 1;
	win->form->next->next->next->col.r = 255;
	win->form->next->next->next->col.g = 0;
	win->form->next->next->next->col.b = 0;
	win->form->next->next->next->col.a = 255;
	win->form->next->next->next->next = NULL;
}

void	scene_4a(t_win *win)
{
	win->form->next->next = (t_form*)malloc(sizeof(t_form));
	win->form->next->next->type = CYLI;
	win->form->next->next->coord.x = 0;
	win->form->next->next->coord.y = -1;
	win->form->next->next->coord.z = 3;
	win->form->next->next->rot.x = 0;
	win->form->next->next->rot.y = -1;
	win->form->next->next->rot.z = 0;
	win->form->next->next->r = 0.1;
	win->form->next->next->col.r = 0;
	win->form->next->next->col.g = 255;
	win->form->next->next->col.b = 255;
	win->form->next->next->col.a = 255;
	scene_4b(win);
}

void	scene_4(t_win *win)
{
	win->form = (t_form*)malloc(sizeof(t_form));
	win->form->type = SPHERE;
	win->form->coord.x = 0;
	win->form->coord.y = 1;
	win->form->coord.z = 3;
	win->form->r = 1.3;
	win->form->col.r = 0;
	win->form->col.g = 0;
	win->form->col.b = 255;
	win->form->col.a = 255;
	win->form->next = (t_form*)malloc(sizeof(t_form));
	win->form->next->type = CONE;
	win->form->next->coord.x = 0;
	win->form->next->coord.y = -1;
	win->form->next->coord.z = 3;
	win->form->next->rot.x = 0;
	win->form->next->rot.y = -1;
	win->form->next->rot.z = 0;
	win->form->next->r = 0.5;
	win->form->next->col.r = 0;
	win->form->next->col.g = 255;
	win->form->next->col.b = 0;
	win->form->next->col.a = 255;
	win->form->next->next = NULL;
	light_2(win);
}
