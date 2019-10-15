/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 08:46:05 by abourin           #+#    #+#             */
/*   Updated: 2019/10/14 09:57:47 by abourin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

void	ft_convert_c(t_segment *seg, t_converter *convert, va_list ap)
{
	unsigned char	result;
	
	if (!(seg) || !(convert))
		return ;
	result = va_arg(ap, int);
	ft_buffer_fillin(result);
}
