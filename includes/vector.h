/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 13:47:32 by psaint-j          #+#    #+#             */
/*   Updated: 2016/09/28 17:25:43 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include "./rtv1.h"
# define O vect(0, 0, 0)
typedef struct	s_vector
{
	float		x;
	float		y;
	float		z;
}				t_vector;

//vectorFonction.c
float			vectorDot(t_vector *v1, t_vector *v2);
t_vector		vectorSub(t_vector *v1, t_vector *v2);
t_vector		vectorScale(float c, t_vector *v);
t_vector		vectorAdd(t_vector *v1, t_vector *v2);
t_vector		vectorNormalize(t_vector *v);
t_vector		vectorCross(t_vector *v1, t_vector *v2);
t_vector		vectorNegative(t_vector *v);
t_vector		vect(float x, float y, float z);
double			vectorMagnitude(t_vector *v);
void			vectorDebug(t_vector debug);
#endif
