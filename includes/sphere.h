/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 16:02:30 by psaint-j          #+#    #+#             */
/*   Updated: 2016/09/28 17:16:25 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H
# include "../includes/rtv1.h"

typedef struct	s_sphere
{
	t_vector	pos;
	float		radius;
	t_color		color;
}				t_sphere;

//sphereFonction.c
t_sphere	sphereConstruct(t_vector pos, float radius, t_color color);
void		sphereDebug(t_sphere debug);
#endif
