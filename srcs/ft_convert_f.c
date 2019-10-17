/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:15:53 by abourin           #+#    #+#             */
/*   Updated: 2019/10/17 17:26:39 by abourin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

static void		ft_float_fill_blanks(char *str, t_segment *seg, int is_negative)
{
	int		i;
	int		len;
	int		max_width;

	len = (int)ft_strlen(str);
	i = 0;
	if (seg->min_width > 0)
	{
		max_width = seg->max_width == -1 ? 0 + len : seg->max_width;
		if (max_width < (int)len)
			max_width = (int)len;
		if (is_negative)
			seg->min_width--;
		while (i < (seg->min_width - max_width))
		{
			ft_buffer_fillin(seg->is_filled_by_zero
				&& !seg->is_left_aligned ? '0' : ' ');
			i++;
		}
	}
}

static char		*ft_catch_infinity_nan_cases(double f)
{
	if (f == INFINITY)
		return (ft_strdup("inf"));
	else if (f == -INFINITY)
		return (ft_strdup("-inf"));
	else if (f != f)
		return (ft_strdup("nan"));
	return (NULL);
}

static char		*ft_init_float_segment(t_segment *seg, double *f)
{
	char	*res;

	if (seg->max_width == -1)
		seg->max_width = 6;
	if ((res = ft_catch_infinity_nan_cases(*f)))
	{
		seg->max_width = 0;
		seg->is_filled_by_zero = 0;
		if (f)
			*f = 0;
	}
	return (res);
}

void			ft_convert_f(t_segment *seg, t_converter *convert, va_list ap)
{
	double			f;
	char			*res;

	if (!seg || !convert)
		return ;
	f = va_arg(ap, double);
	res = ft_init_float_segment(seg, &f);
	if (!res)
		if (!(res = ft_ftoa(f, seg->max_width)))
			return ;
	if (f < 0 && seg->is_filled_by_zero)
		ft_buffer_fillin('-');
	if (!seg->is_left_aligned)
		ft_float_fill_blanks(res, seg, f < 0);
	if (f < 0 && !seg->is_filled_by_zero)
		ft_buffer_fillin('-');
	ft_process_max_width(res, seg);
	ft_buffer_str_fillin(f < 0 && (seg->is_filled_by_zero
		|| seg->max_width > (int)ft_strlen(res) - 1) ? res : res);
	if (seg->is_left_aligned)
		ft_float_fill_blanks(res, seg, f < 0);
	free(res);
}
