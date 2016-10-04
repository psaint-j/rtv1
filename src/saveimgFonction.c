/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saveimgFonction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <psaint-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:39:45 by psaint-j          #+#    #+#             */
/*   Updated: 2016/10/04 11:43:54 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	savePPM(char *filename, unsigned char *img, int width, int height)
{
	FILE	*f;

	f = fopen(filename, "w");
	fprintf(f, "P6 %d %d %d\n", width, height, 255);
	fwrite(img, 3, width*height, f);
	fclose(f);
}