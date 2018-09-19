/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 17:54:47 by azaporoz          #+#    #+#             */
/*   Updated: 2018/09/19 17:54:47 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct		s_vec
{
	int				x;
	struct s_vec	*next;
}					t_vec;

int main()
{
	t_vec *first;
	t_vec *cp;
	t_vec *res;

	first = (t_vec*)malloc(sizeof(t_vec));
	first->x = 1;
	first->next = (t_vec*)malloc(sizeof(t_vec));
	first->next->x = 2;
	first->next->next = NULL;

	cp = first;
	res = cp;
	// cp = first->next;
	cp = cp->next;

	printf("CP::%d\n", cp->x);
	printf("RES::%d\n", res->x);
}
