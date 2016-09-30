/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <psaint-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 15:57:02 by psaint-j          #+#    #+#             */
/*   Updated: 2016/09/30 16:15:49 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H
#include "./rtv1.h"

/* Ray */
typedef struct	s_ray
{
	t_vector	start;
	t_vector	dir;
}				t_ray;

t_ray			rayConstruct(t_vector start, t_vector dir);
void			rayDebug(t_ray debug);

#endif