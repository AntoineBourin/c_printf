/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 08:46:05 by abourin           #+#    #+#             */
/*   Updated: 2019/10/17 09:09:48 by abourin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

void	ft_convert_c(t_segment *seg, t_converter *convert, va_list ap)
{
	unsigned char	res;
	char			*result;
	
	if (!(seg) || !(convert))
		return ;
	res = va_arg(ap, int);
	if (!(result = malloc(sizeof(char) * 2)))
		return ;
	result[0] = res;
	result[1] = '\0';
	if (!seg->is_left_aligned)
        ft_fill_blanks(result[0] == '\0' ? "a" : result, seg, seg->is_filled_by_zero);
	ft_buffer_fillin(result[0]);
	if (seg->is_left_aligned)
		ft_fill_blanks(result[0] == '\0' ? "a" : result, seg, seg->is_filled_by_zero);
	free(result);
}
