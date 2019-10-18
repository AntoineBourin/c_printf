/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:34:18 by abourin           #+#    #+#             */
/*   Updated: 2019/10/18 17:08:09 by abourin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_fill_int_blanks(char *str, t_segment *seg)
{
	int		i;
	int		len;
	int		max_width;

	len = (int)ft_strlen(str);
	if (str[0] != '-' && seg->is_spaced)
		len++;
	i = 0;
	if (seg->min_width > 0)
	{
		max_width = seg->max_width == -1 ? 0 + len : seg->max_width;
		if (max_width < (int)len)
			max_width = (int)len;
		if (str[0] == '-' && seg->max_width >= len)
			seg->min_width--;
		while (i < (seg->min_width - max_width))
		{
			ft_buffer_fillin(seg->max_width == -1
					&& seg->is_filled_by_zero ? '0' : ' ');
			i++;
		}
	}
}

void	ft_process_max_width(char *str, t_segment *seg)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	if (str[0] == '-')
		len--;
	else if (seg->is_spaced)
		len++;
	i = 0;
	if (seg->max_width != -1)
	{
		while (i < (seg->max_width - len))
		{
			ft_buffer_fillin('0');
			i++;
		}
	}
}

void	ft_add_spaces(int n, t_segment *seg)
{
	if (n >= 0 && seg->is_spaced)
	{
		ft_buffer_fillin(' ');
	}
}

void	ft_convert_d_i(t_segment *seg, t_converter *convert, va_list ap)
{
	int		n;
	char	*res;

	if (!seg || !convert)
		return ;
	n = va_arg(ap, int);
	if (!(res = ft_itoa(n)))
		return ;
	ft_add_spaces(n, seg);
	if (n < 0 && ((seg->min_width < (int)ft_strlen(res))
		|| (seg->max_width == -1 && seg->is_filled_by_zero)))
		ft_buffer_fillin('-');
	if (!seg->is_left_aligned)
		ft_fill_int_blanks(seg->max_width == 0 && n == 0 ? "" : res, seg);
	if (n < 0 && (seg->min_width >= (int)ft_strlen(res))
		&& (!seg->is_filled_by_zero || seg->max_width != -1))
		ft_buffer_fillin('-');
	ft_process_max_width(res, seg);
	if (seg->max_width != 0 || n != 0)
		ft_buffer_str_fillin(n < 0 ? res + 1 : res);
	if (seg->is_left_aligned)
		ft_fill_int_blanks(seg->max_width == 0 && n == 0 ? "" : res, seg);
	free(res);
}
