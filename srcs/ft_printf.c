/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:12:08 by abourin           #+#    #+#             */
/*   Updated: 2019/10/22 10:40:49 by abourin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_segment		*ft_init_segment(int index)
{
	t_segment	*seg;

	if (!(seg = malloc(1 * sizeof(t_segment))))
		return (0);
	seg->nb_modifiers = 0;
	seg->min_width = 0;
	seg->max_width = -1;
	seg->is_spaced = 0;
	seg->is_left_aligned = 0;
	seg->is_filled_by_zero = 0;
	seg->index = index;
	return (seg);
}

int				ft_free_segment(t_segment *seg, char *str)
{
	if (seg)
		free(seg);
	if (str)
		free(str);
	return (-1);
}

int				ft_process_segment(char *str, va_list ap, int index)
{
	t_segment	*seg;
	char		conv;
	int			size;

	size = 0;
	if (!(seg = ft_init_segment(index)))
		return (-1);
	str++;
	size = ft_get_segment_size(str);
	if (size <= 0)
		return (ft_free_segment(seg, NULL));
	if (!(str = ft_replace_identifier(str, ap)))
		return (ft_free_segment(seg, NULL));
	ft_process_flags(str, seg, size);
	if (!(conv = ft_get_current_conv(str)))
		return (ft_free_segment(seg, str));
	if (seg->is_spaced && conv != 's' && conv != '%'
		&& conv != 'd' && conv != 'i' && conv != 'c' && conv != 'x'
		&& conv != 'X' && conv != 'u' && conv != 'p')
		ft_buffer_fillin(' ');
	ft_process_conversion(conv, seg, ap);
	free(seg);
	free(str);
	return (size);
}

int				ft_printf(const char *str, ...)
{
	va_list		ap;
	char		*cs;
	int			i;
	int			seg_size;

	if (!str)
		return (-1);
	cs = (char *)str;
	i = 0;
	va_start(ap, str);
	while (cs[i])
	{
		if (cs[i] == '%')
		{
			seg_size = ft_process_segment(cs + i, ap, i);
			if (seg_size > 0)
				i += seg_size;
		}
		else
			ft_buffer_fillin(cs[i]);
		i++;
	}
	va_end(ap);
	return (ft_fillout_buffer(1, 0));
}
