/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:08:41 by abourin           #+#    #+#             */
/*   Updated: 2019/10/15 16:13:14 by abourin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

void	ft_convert_n(t_segment *seg, t_converter *convert, va_list ap)
{
	int		*n;

	if (!seg || !convert)
		return ;
	n = va_arg(ap, int *);
	*n = ft_fillout_buffer(1);
}
