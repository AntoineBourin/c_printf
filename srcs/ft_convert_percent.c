/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:45:49 by abourin           #+#    #+#             */
/*   Updated: 2019/10/18 15:41:38 by abourin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		ft_convert_percent(t_segment *seg, t_converter *convert, va_list ap)
{
	char	res[2];

	res[0] = '%';
	res[1] = '\0';
	if (!seg || !convert)
		return ;
	(void)ap;
	if (!seg->is_left_aligned)
		ft_fill_blanks(res, seg, seg->is_filled_by_zero);
	ft_buffer_fillin('%');
	if (seg->is_left_aligned)
		ft_fill_blanks(res, seg, seg->is_filled_by_zero);
}
