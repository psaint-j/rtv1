/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayFonction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <psaint-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 16:13:35 by psaint-j          #+#    #+#             */
/*   Updated: 2016/09/30 20:09:55 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/rtv1.h"

t_ray	rayConstruct(t_vector start, t_vector dir)
{
	t_ray	result;

	result.start = start;
	result.dir = dir;
	return (result);
}

void	rayDebug(t_ray debug)
{
	printf("(Ray)\n");
	printf("start(%f, %f, %f)\n", debug.start.x, debug.start.x, debug.start.z);
	printf("dir(%f, %f, %f)\n", debug.dir.x, debug.dir.x, debug.dir.z);
}