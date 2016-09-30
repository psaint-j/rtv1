/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 13:43:48 by psaint-j          #+#    #+#             */
/*   Updated: 2016/09/28 13:47:19 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H
#include "./rtv1.h"

typedef struct	s_color
{
	float		red;
	float		green;
	float		blue;
}				t_color;

//colorFonction.c
t_color			colorConstruct(float r, float g, float b);
void			colorDebug(t_color debug);
#endif
