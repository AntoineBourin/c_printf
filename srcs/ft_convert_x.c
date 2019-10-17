/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 09:18:50 by abourin           #+#    #+#             */
/*   Updated: 2019/10/17 18:02:43 by abourin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

void	ft_convert_x(t_segment *seg, t_converter *convert, va_list ap)
{
	unsigned int		n;
	char				*base;
	char				*result;

	if (!seg || !convert)
		return ;
	n = va_arg(ap, unsigned int);
	if (!(base = ft_strdup(convert->conversion == 'X'
			? "0123456789ABCDEF" : "0123456789abcdef")))
		return ;
	if (!(result = ft_uitoa_base(n, base)))
	{
		free(base);
		return ;
	}
	if (!seg->is_left_aligned)
		ft_fill_int_blanks(n == 0 && seg->max_width == 0 ? "" : result, seg);
	ft_process_max_width(result, seg);
	if (n != 0 || seg->max_width != 0)
		ft_buffer_str_fillin(result);
	if (seg->is_left_aligned)
		ft_fill_int_blanks(n == 0 && seg->max_width == 0 ? "" : result, seg);
	free(base);
	free(result);
}
