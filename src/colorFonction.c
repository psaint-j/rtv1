/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorFontion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 14:31:19 by psaint-j          #+#    #+#             */
/*   Updated: 2016/09/28 16:12:02 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/rtv1.h"

t_color		colorConstruct(float r, float g, float b)
{
	t_color result;
	result.red = r;
	result.green = g;
	result.blue = b;
	return (result);
}

void		colorDebug(t_color debug)
{
	printf("red = %f\ngreen = %f\nblue = %f\n", debug.red, debug.green, debug.blue);
}
