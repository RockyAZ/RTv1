/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 17:42:43 by azaporoz          #+#    #+#             */
/*   Updated: 2018/06/21 17:42:43 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

void	error(char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}
