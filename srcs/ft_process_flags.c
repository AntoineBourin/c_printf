/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 10:16:37 by abourin           #+#    #+#             */
/*   Updated: 2019/10/21 15:17:19 by abourin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_process_align_space(char c, t_segment *seg)
{
	if (c == ' ')
		seg->is_spaced = 1;
	if (c == '-')
		seg->is_left_aligned = 1;
}

void	ft_process_additional(char *str, t_segment *seg, int i, int max_size)
{
	while (str[i] && i < max_size)
	{
		ft_process_align_space(str[i], seg);
		i++;
	}
}

int		ft_get_width(char *str, int i, int max_size, t_segment *seg)
{
	int		beg_ind;
	int		end_ind;
	char	*min_width;

	beg_ind = i;
	while ((str[i] >= '0' && str[i] <= '9'))
		i++;
	end_ind = i;
	if (!(min_width = malloc((end_ind - beg_ind + 1) * sizeof(char))))
		return (-1);
	i = 0;
	while (beg_ind < end_ind)
	{
		min_width[i] = str[beg_ind];
		i++;
		beg_ind++;
	}
	min_width[i] = '\0';
	ft_process_additional(str, seg, i + 1, max_size);
	return (ft_atoi(min_width));
}

void	ft_process_flags(char *str, t_segment *seg, int max_size)
{
	int	i;

	i = 0;
	while (i < max_size && str[i])
	{
		ft_process_align_space(str[i], seg);
		if (str[i] == '.')
		{
			seg->max_width = ft_get_width(str, i + 1, max_size, seg);
			return ;
		}
		if (str[i] >= '0' && str[i] <= '9')
		{
			seg->min_width = ft_get_width(str, str[i] == '0'
					? i + 1 : i, max_size, seg);
			if (str[i] == '0')
				seg->is_filled_by_zero = 1;
			while (str[i] >= '0' && str[i] <= '9')
				i++;
			if (str[i] == '.')
				seg->max_width = ft_get_width(str, i + 1, max_size, seg);
			continue;
		}
		i++;
	}
}
