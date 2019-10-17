/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_x_X.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 09:18:50 by abourin           #+#    #+#             */
/*   Updated: 2019/10/16 17:24:19 by abourin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

void	ft_convert_x_X(t_segment *seg, t_converter *convert, va_list ap)
{
	unsigned int		n;
	char				*base;
	char				*result;

	if (!seg || !convert)
		return ;
	n = va_arg(ap, unsigned int);
	if (n == 0 && seg->max_width == 0)
		return ;
	if (!(base = malloc(16 * sizeof(char))))
		return ;
	if (convert->conversion == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (!(result = ft_uitoa_base(n, base)))
		return ;
	if (!seg->is_left_aligned)
		ft_fill_int_blanks(result, seg);
	ft_process_max_width(result, seg);
	ft_buffer_str_fillin(result);
	if (seg->is_left_aligned)
		ft_fill_int_blanks(result, seg);
	free(result);
}
