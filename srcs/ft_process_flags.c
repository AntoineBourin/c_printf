/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 10:16:37 by abourin           #+#    #+#             */
/*   Updated: 2019/10/17 13:21:01 by abourin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

int		ft_get_width(char *str, int i, int max_size)
{
	int		beg_ind;
	int		end_ind;
	char	*min_width;

	beg_ind = i;
	while ((str[i] >= '0' && str[i] <= '9'))
		i++;
	end_ind = i;
	min_width = malloc((end_ind - beg_ind + 1) * sizeof(char));
	i = 0;
	while (beg_ind < end_ind && i < max_size)
	{
		min_width[i] = str[beg_ind];
		i++;
		beg_ind++;
	}
	min_width[i] = '\0';
	return (ft_atoi(min_width));
}

void	ft_process_flags(char *str, t_segment *seg, int max_size)
{
	int	i;

	i = 0;
	while (i < max_size && str[i])
	{
		if (str[i] == ' ')
			seg->is_spaced = 1;
		if (str[i] == '-')
			seg->is_left_aligned = 1;
		if (str[i] == '.')
		{
			seg->max_width = ft_get_width(str, i + 1, max_size);
			return ;
		}
		if (str[i] >= '0' && str[i] <= '9')
		{
			seg->min_width = ft_get_width(str, str[i] == '0' ? i + 1 : i, max_size);
			if (str[i] == '0')
				seg->is_filled_by_zero = 1;
			while (str[i] >= '0' && str[i] <= '9')
				i++;
			if (str[i] == '.')
				seg->max_width = ft_get_width(str, i + 1, max_size);
			continue;
		}
		i++;
	}
}
