/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:05:57 by abourin           #+#    #+#             */
/*   Updated: 2019/10/18 15:40:36 by abourin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_variable_adress(void *ptr, t_segment *seg)
{
	uintptr_t	k;
	char		*result;
	int			i;

	i = 0;
	k = (uintptr_t)ptr;
	result = ft_itoa_hex(k);
	seg->min_width -= 2;
	if (!seg->is_left_aligned && !seg->is_filled_by_zero)
		ft_fill_int_blanks(result, seg);
	ft_buffer_fillin('0');
	ft_buffer_fillin('x');
	if (!seg->is_left_aligned && seg->is_filled_by_zero)
		ft_fill_int_blanks(result, seg);
	ft_process_max_width(result, seg);
	while (result[i])
	{
		ft_buffer_fillin(result[i]);
		i++;
	}
	if (seg->is_left_aligned)
		ft_fill_blanks(result, seg, 0);
}

void	ft_convert_p(t_segment *seg, t_converter *convert, va_list ap)
{
	void	*ptr;

	if (!seg || !convert)
		return ;
	ptr = va_arg(ap, void *);
	ft_print_variable_adress(ptr, seg);
}
