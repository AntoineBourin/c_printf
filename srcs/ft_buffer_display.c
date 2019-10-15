/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 13:36:23 by abourin           #+#    #+#             */
/*   Updated: 2019/10/15 16:08:39 by abourin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

int		ft_get_buffer_size(void)
{
	int		i;

	i = 0;
	while (g_buff[i] != 0)
		i++;
	return (i);
}

void	ft_buffer_str_fillin(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_buffer_fillin(str[i]);
		i++;
	}
}

void	ft_buffer_fillin(char c)
{
	int		s_buff;

	s_buff = ft_get_buffer_size();
	if (s_buff >= 31)
	{
		ft_fillout_buffer(0);
		g_buff[0] = c;
	}
	else
		g_buff[s_buff] = c;
}

int		ft_fillout_buffer(int reset)
{
	static int	count = 0;

	if (reset)
		count = 0;
	count += ft_get_buffer_size();
	write(1, g_buff, ft_get_buffer_size());
	ft_reset_buffer();
	return (count);
}

void	ft_reset_buffer(void)
{
	int				i;

	i = 0;
	while (i < 32)
	{
		g_buff[i] = 0;
		i++;
	}
}
