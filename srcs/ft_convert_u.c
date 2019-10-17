/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:41:00 by abourin           #+#    #+#             */
/*   Updated: 2019/10/17 17:58:03 by abourin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

void	ft_convert_u(t_segment *seg, t_converter *convert, va_list ap)
{
	unsigned int	n;
	char			*res;

	if (!seg || !convert)
		return ;
	n = va_arg(ap, unsigned int);
	if (!(res = ft_uitoa(n)))
		return ;
	if (!seg->is_left_aligned)
		ft_fill_int_blanks(seg->max_width == 0 && n == 0 ? "" : res, seg);
	ft_process_max_width(res, seg);
	if (seg->max_width != 0 || n != 0)
		ft_buffer_str_fillin(res);
	if (seg->is_left_aligned)
		ft_fill_int_blanks(seg->max_width == 0 && n == 0 ? "" : res, seg);
	free(res);
}
