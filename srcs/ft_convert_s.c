/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 10:02:06 by abourin           #+#    #+#             */
/*   Updated: 2019/10/15 15:20:16 by abourin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

void	ft_convert_s(t_segment *seg, t_converter *convert, va_list ap)
{
	char	*result;
	int		i;

	if (!seg || !convert)
		return ;
	result = va_arg(ap, char *);
	i = 0;
	if (!seg->is_left_aligned)
		ft_fill_blanks(result, seg, seg->is_filled_by_zero);
	while (result[i])
	{
		if (i >= seg->max_width && seg->max_width > -1)
			break ;
		ft_buffer_fillin(result[i]);
		i++;
	}
	if (seg->is_left_aligned)
		ft_fill_blanks(result, seg, 0);
}
