/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:07:11 by abourin           #+#    #+#             */
/*   Updated: 2019/10/15 18:16:59 by abourin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

char	*ft_ftoa(float f, int precision)
{
	int		n;
	double	dec;

	(void)precision;
	n = (float)f;
	dec = f - n;
	printf("%f\n", f);
	printf("%f\n", dec);
	printf("%d\n", n);
}
