/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 13:40:36 by psaint-j          #+#    #+#             */
/*   Updated: 2016/09/28 13:43:38 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H
# include "./rtv1.h"

typedef struct	s_light
{
	t_vector	pos;
	t_color		intensity;
}				t_light;
//lightFonction.c
t_light			lightConstruct(t_vector pos, t_color intensity);
void			lightDebug(t_light debug);
#endif
